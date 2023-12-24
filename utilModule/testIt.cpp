

#ifdef USE_MODULES
#include <string>
#include <iostream>
import utilModule;
#else
#include "Foo.h"
#include "Accumulator.h"
#include "MovingAverage.h"
#include "StringUtils.h"
#endif

void test_1()
	{
	UTILS::Foo c;
	c.fizzBuzz(15);
	}

void test_2()
	{
	UTILS::MathFuncs::Accumulator acc;
	acc.reset();

	UTILS::MovingAvg avg(3);
	avg.reset();

	for (double f=0.0; f < 10.0; f+=1.1)
		{
		acc.add(f);
		avg.add(f);
		std::cout<<"Mean="<<acc.mean()<<" MovingAvg="<<avg.mean()<<std::endl;
		}
	}

void test_3()
	{
	const std::string lowerS("hello world");
	const std::string upperS=UTILS::STRING::upperCase(lowerS);
	std::cout<<"lower=["<<lowerS<<"]  upper=["<<upperS<<"]"<<std::endl;
	}

int main()
	{
	test_1();
	test_2();
	test_3();
	return 0;
	}

