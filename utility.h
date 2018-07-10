#include <iostream>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <cstddef>
#include <fstream>
#include <cctype>
#include <ctime>
#include <string>
#include <sstream>

using namespace std;

enum Error_code
{
	success, fail, range_error, underflow, overflow, fatal,
	not_present, duplicate_error, entry_inserted, entry_found,
	internal_error
};