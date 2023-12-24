#ifndef INC_MOVING_AVERAGE_H
#define	INC_MOVING_AVERAGE_H

#include "Accumulator.h"

MODULE_IF
namespace UTILS
    {
	class	MovingAvg
		{
		public:

			MovingAvg() = delete;
			explicit MovingAvg(const std::size_t windowSize)
				: m_windowSize(windowSize)
				{ }

			MovingAvg(const MovingAvg& rhs)
				: m_windowSize(rhs.m_windowSize)
				, m_acc(rhs.m_acc)
				{ }

			MovingAvg& operator=(const MovingAvg& rhs)
				{
				if ( &rhs != this )
					{
					m_windowSize	= rhs.m_windowSize;
					m_acc			= rhs.m_acc;
					}
				return *this;
				}

			~MovingAvg() = default;

			void	reset()
				{
				m_acc.reset();
				}

			void	add(const double x)
				{
				if ( m_acc.size() >= m_windowSize )
					{
					m_acc.remove(m_acc.mean());
					}
				m_acc.add(x);
				}

			double mean() const
				{
				return m_acc.mean();
				}

		private:
			std::size_t						m_windowSize;
			UTILS::MathFuncs::Accumulator	m_acc;
		};
    }
#endif

