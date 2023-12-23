
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


// include the project headers/classes
#include "Foo.h"
//#include "Accumulator.h"
//#include "MovingAverage.h"
//#include "StringUtils.h"

export module utilModule;


//import "Foo.h";

//export UTILS::Foo;

//export namespace UTILS {};
//export class UTIL::Foo;
