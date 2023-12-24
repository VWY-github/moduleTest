
module;


// explicitly list all the C++ stdlib includes needed by the headers/classes in the module
#include "Accumulator.h"
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
#include "StringUtils.h"


// Various failed attempts at fixing errors
export namespace UTILS {};
export namespace UTILS::MathFuncs {};
//export class UTILS::MathFuncs::Accumulator;
//export UTILS::MathFuncs::Accumulator;
//export MathFuncs::Accumulator;

