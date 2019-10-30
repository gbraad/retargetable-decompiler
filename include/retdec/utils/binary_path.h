/**
 * @file include/retdec/utils/binary_path.h
 * @brief Absolute path of currently running binary getters.
 * @copyright (c) 2017 Avast Software, licensed under the MIT license
 */

#ifndef RETDEC_UTILS_BINARY_PATH_H
#define RETDEC_UTILS_BINARY_PATH_H

#include <filesystem>

#include <whereami/whereami.h>

namespace retdec {
namespace utils {

std::filesystem::path getThisBinaryPath();
std::filesystem::path getThisBinaryDirectoryPath();

} // namespace utils
} // namespace retdec

#endif
