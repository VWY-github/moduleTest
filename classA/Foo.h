#ifndef FOO_INC_H
#define FOO_INC_H

#include <iostream>

//MODULE_IF
namespace UTILS
	{
	MODULE_IF class Foo
		{
		public:
			Foo() = default;
			~Foo() = default;

			void fizzBuzz(const int n)
				{
				bool printInt;
				for (int i=1; i <= n; ++i)
					{
					printInt=true;
					if ( 0 == i % 3 )
						{
						std::cout<<"Fizz";
						printInt=false;
						}
					if ( 0 == i % 5 )
						{
						std::cout<<"Buzz";
						printInt=false;
						}

					if ( printInt )
						{
						std::cout<<i;
						}

					std::cout<<std::endl;
					}
				}
		};
	}
#endif
