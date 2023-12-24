#ifndef INC_ACCUMULATOR_H
#define INC_ACCUMULATOR_H

#include <cmath>
#include <vector>

MODULE_IF
namespace UTILS
	{
	namespace MathFuncs
		{
		class Accumulator
			{
			public:
				Accumulator()
					: m_N(0)
					, m_M(0)
					, m_S(0)
					{ }

				~Accumulator() = default;
				Accumulator(const Accumulator& rhs) = default;
				Accumulator& operator=(const Accumulator& rhs) = default;

				void reset()
					{
					m_N = 0;
					m_M = 0;
					m_S = 0;
					}

				void add(const double x)
					{
					++m_N;
					const double nextM(m_M + (x - m_M) / m_N);
					m_S += (x - m_M) * (x - nextM);
					m_M = nextM;
					}

				void add(const std::vector<double>& xVec)
					{
					for (const auto& i: xVec)
						{
						add(i);
						}
					}

				void remove(const double x)
					{
					if ( 2 > size())
						{
						reset();
						}
					else
						{
						const double old = (m_N * m_M - x) / (m_N - 1.0);
						m_S -= (x - m_M) * (x - old);
						m_M = old;
						--m_N;
						}
					}

				size_t size() const
					{
					return static_cast<size_t>(m_N);
					}

				double mean() const
					{
					return m_M;
					}

				double sum() const
					{
					return (m_M * m_N);
					}

				double variancePopulation() const
					{
					return (m_N > 1 ? (m_S / m_N) : 0.0);
					}

				double varianceSample() const
					{
					return (m_N > 1 ? (m_S / (m_N - 1)) : 0.0);
					}

				double standardDeviationPopulation() const
					{
					return sqrt(variancePopulation());
					}

				double standardDeviationSample() const
					{
					return sqrt(varianceSample());
					}

			private:
				double m_N;
				double m_M;
				double m_S;
			};
		}
	}
#endif
