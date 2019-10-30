/**
* @file tests/utils/binary_path_tests.cpp
* @brief Tests for the @c binary_path module.
* @copyright (c) 2017 Avast Software, licensed under the MIT license
*/

#include <filesystem>

#include <gtest/gtest.h>

#include "retdec/utils/binary_path.h"

using namespace ::testing;

namespace retdec {
namespace utils {
namespace tests {

/**
* @brief Tests for the @c binary_path module.
*/
class ThisBinaryPathTests: public Test {};

//
// getThisBinaryPath()
//

TEST_F(ThisBinaryPathTests,
CorrectBinaryPathDetection) {
	EXPECT_TRUE(std::filesystem::is_regular_file(getThisBinaryPath()));
}

//
// getThisBinaryDirectoryPath()
//

TEST_F(ThisBinaryPathTests,
CorrectBinaryDirPathDetection) {
	EXPECT_TRUE(std::filesystem::is_directory(getThisBinaryDirectoryPath()));
}

} // namespace tests
} // namespace utils
} // namespace retdec
