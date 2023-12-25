#ifndef INC_STRINGUTILS_H
#define	INC_STRINGUTILS_H

#include <cstdint>
#include <iostream>
#include <string>
#include <string_view>
#include <ranges>
#include <sstream>
#include <vector>
#include <iomanip>
#include <typeinfo>
#include <algorithm>

MODULE_IF
namespace UTILS
    {
    namespace STRING
        {
		/*
		inline std::string	upperCase(std::string s)
			{
			std::transform(s.begin(),s.end(),s.begin(),
				[](unsigned char c)
					{
					return std::toupper(c);
					});
			return s;
			}

		inline std::string	lowerCase(std::string s)
			{
			std::transform(s.begin(),s.end(),s.begin(),
				[](unsigned char c)
					{
					return std::tolower(c);
					});
			return s;
			}
*/
		inline std::string toString(const float& val)
			{
            std::ostringstream os;
            return ( ( os <<std::setprecision(std::numeric_limits<float>::max_digits10) << val ) ? os.str(): "" );
			}

		inline void fromString(const std::string& str, float& val)
			{
			try
				{
				val=std::stof(str);
				}
			catch(const std::exception& e)
				{
				const std::string msg="Failed to convert string \""+str+"\" to type "+typeid(float).name()+":"+e.what();
				throw std::runtime_error(msg);
				}
			}

        static inline void removeChars(std::string& str,const std::string& charsToRemove)
            {
            std::string::size_type pos(0);
            while ( true )
                {
                pos = str.find_first_of(charsToRemove, pos );
                if ( std::string::npos == pos )
                    {
                    break;
                    }
                str.erase( pos, 1 );
                }
            }

        static inline std::string toHexString(const uint32_t _value,const size_t _minLen)
            {
            std::stringstream os;
            os << std::setfill('0')<< std::setw(int(_minLen))<< std::hex << _value;
			return os.str();
            }

		template<typename T>
        inline bool fromHexString(const std::string& str, T& val)
            {
			std::istringstream is(str);
			return ( (is >> std::hex >> val)?true:false);
            }

		static inline bool stripQuotes(std::string& s,const std::string& stripList="\"")
			{
			const size_t lQuote=s.find_first_of(stripList);
			if ( std::string::npos != lQuote )
				{
				const size_t rQuote = s.find_last_of(stripList);
				if ( std::string::npos != rQuote )
					{
					if ( lQuote != rQuote )
						{
						// have a distinct pair of quotes, so remove them
						s = s.substr(lQuote+1,(rQuote-lQuote-1));
						return true;
						}
					}
				}
			return false;
			}

		static void splitLines(const std::string_view data, std::vector<std::string>& lines)
			{
			lines.clear();
			if ( ! data.empty() )
				{
				static constexpr auto delimiter{'\n'};
				for (const auto oneLine: std::views::split(data, delimiter))
					{
					const auto s( std::string_view(oneLine.begin(),oneLine.end()) );
					if ( ! s.empty() )
						{
						lines.emplace_back(s);
						}
					}
				}
			}
        }
    }
#endif

