/**
 * @file include/retdec/utils/filesystem.h
 * @brief Abstraction over different C++ <filesystem> implementations.
 * @copyright (c) 2019 Avast Software, licensed under the MIT license
 *
 * Unfortunatelly, even though C++17 has <filesystem>, it is not in GCC 7 and
 * macOS 10.14 and older.
 * Right now, we don't want to require GCC 8 and macOS 10.15 and newer. So,
 * we use this <filesystem> encapsulation.
 * This can be removed once the new compilers are more widespread and we drop
 * the support for the older ones.
 */

#ifndef RETDEC_UTILS_FILESYSTEM_H
#define RETDEC_UTILS_FILESYSTEM_H

#include "retdec/utils/os.h"

#if __has_include(<filesystem>)
	#include <filesystem>
	namespace fs = std::filesystem;
#else
	#include <experimental/filesystem>
	namespace fs = std::experimental::filesystem;
#endif

#endif
