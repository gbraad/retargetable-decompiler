/**
 * @file src/cpdetect/compiler_detector/raw_data_compiler.cpp
 * @brief Methods of RawDataCompiler class.
 * @copyright (c) 2017 Avast Software, licensed under the MIT license
 */

#include "retdec/cpdetect/compiler_detector/heuristics/heuristics.h"
#include "retdec/cpdetect/compiler_detector/raw_data_compiler.h"
#include "retdec/cpdetect/settings.h"

using namespace retdec::fileformat;

namespace retdec {
namespace cpdetect {

/**
 * Constructor
 */
RawDataCompiler::RawDataCompiler(
		fileformat::RawDataFormat &parser, DetectParams &params, ToolInformation &tools)
	: CompilerDetector(parser, params, tools)
{
	heuristics = new Heuristics(parser, *search, toolInfo);
	externalSuffixes = EXTERNAL_DATABASE_SUFFIXES;
	auto bitWidth = parser.getWordLength();

	fs::path pathPe;
	fs::path pathElf;
	fs::path pathMacho;

	fs::path yaraPath(pathToShared);
	yaraPath.append(YARA_RULES_PATH);

	switch(targetArchitecture)
	{
		case Architecture::X86:
			pathPe = yaraPath / "pe" / "x86";
			pathElf = yaraPath / "elf" / "x86";
			pathMacho = yaraPath / "macho" / "x86";
			break;

		case Architecture::X86_64:
			pathPe = yaraPath / "pe" / "x64";
			pathElf = yaraPath / "elf" / "x64";
			pathMacho = yaraPath / "macho" / "x64";
			break;

		case Architecture::ARM:
			if (bitWidth == 32)
			{
				pathPe = yaraPath / "pe" / "arm";
				pathElf = yaraPath / "elf" / "arm";
				pathMacho = yaraPath / "macho" / "arm";
			}
			else
			{
				pathElf = yaraPath / "elf" / "arm64";
			}
			break;

		case Architecture::POWERPC:
			if (bitWidth == 32)
			{
				pathElf = yaraPath / "elf" / "ppc";
				pathMacho = yaraPath / "macho" / "ppc";
			}
			else
			{
				pathElf = yaraPath / "elf" / "ppc64";
				pathMacho = yaraPath / "macho" / "ppc64";
			}
			break;

		case Architecture::MIPS:
			if (bitWidth == 32)
			{
				pathElf = yaraPath / "elf" / "mips";
			}
			else
			{
				pathElf = yaraPath / "elf" / "mips64";
			}
			break;

		default:
			break;
	}

	populateInternalPaths(pathPe);
	populateInternalPaths(pathElf);
	populateInternalPaths(pathMacho);

}

} // namespace cpdetect
} // namespace retdec
