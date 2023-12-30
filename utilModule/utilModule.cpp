
module;


// explicitly list all the C++ stdlib includes needed by the headers/classes in the module
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <ranges>
#include <sstream>
#include <string>
#include <string_view>
#include <typeinfo>
#include <vector>

export module utilModule;

// include the project headers/classes
#include "Foo.h"
#include "Accumulator.h"
#include "MovingAverage.h"
#include "StringUtils.h"	 // this compiled into module ok, but causes ICE when attempted used


