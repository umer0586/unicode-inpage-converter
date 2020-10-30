/*
 * Author
 * 	Umer Farooq
 */

#include "Converter.h"
#include <regex>
#include <iterator>


Converter::Converter()
{

	this->buildITUmapping();
	this->buildUTImapping();

}

void Converter::buildITUmapping()
{

//--------------------- These replacements should occurs first------------------------
					// See inpageToUnicode() function for detail

	this->ITUmapping.insert(std::make_pair(L"\u0004\u00A4\u0004\u00BF",L"\u06CC\u0626"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u0081\u0004\b",L"\u0627\u0004\b"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u0081\u0004\u00BF",L"\u0623"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00A2\u0004\u00BF",L"\u0624"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u0081\u0004\u00B3",L"\u0622"));

//------------------------------------------------------------------------------------


	this->ITUmapping.insert(std::make_pair(L"\u0004\u00A1",L"\u06BA"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00A8",L"\u064D"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00D1",L"\u06F1"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00D2",L"\u06F2"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00D3",L"\u06F3"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00D4",L"\u06F4"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00D5",L"\u06F5"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00D6",L"\u06F6"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00D7",L"\u06F7"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00D8",L"\u06F8"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00D9",L"\u06F9"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00D0",L"\u06F0"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u203A",L"\u0642"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00A2",L"\u0648"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u02DC",L"\u0639"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u017D",L"\u0631"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u201E",L"\u062A"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00A5",L"\u06D2"));

	// let this line be commented
	//this->ITUmapping.insert(std::make_pair(L"\u0004\u00A3",L"\u0621"));

	this->ITUmapping.insert(std::make_pair(L"\u0004\u00A4",L"\u06CC"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00A6",L"\u06C1"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u0192",L"\u067E"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00F2",L"\u060E"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u0081",L"\u0627"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u2019",L"\u0633"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u2039",L"\u062F"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u0161",L"\u0641"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u009D",L"\u06AF"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00A7",L"\u06BE"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u2021",L"\u062C"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u0153",L"\u06A9"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u017E",L"\u0644"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00EA",L"\u061B"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u0090",L"\u0632"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u201C",L"\u0634"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u02C6",L"\u0686"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u2013",L"\u0637"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u201A",L"\u0628"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00A0",L"\u0646"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u0178",L"\u0645"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00ED",L"\u060C"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00F3",L"\u06D4"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00C7",L"\u064B"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00B8",L"\u064A"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00F8",L"\u0610"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00A3",L"\u0626"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00B5",L"\u064C"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00AD",L"\u0651"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00B1",L"\u0652"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00F6",L"\uFDFA"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00AE",L"\u0611"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u008F",L"\u0691"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u2026",L"\u0679"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00F7",L"\u0601"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00BE",L"\u0657"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00BD",L"\u0670"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00B9",L"\u06C3"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00AC",L"\u064F"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00FD",L"\u2018"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00FE",L"\u2019"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00CF",L"\u0614"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00B3",L"\u0653"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u201D",L"\u0635"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u0152",L"\u0688"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00B0",L"\u0656"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u2122",L"\u063A"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u2030",L"\u062D"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u2022",L"\u0636"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u0160",L"\u062E"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00E7",L"\u0612"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u008D",L"\u0630"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u2018",L"\u0698"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u2020",L"\u062B"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u2014",L"\u0638"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00E6",L"\u0613"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00AA",L"\u0650"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00AB",L"\u064E"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00EE",L"\u061F"));

	this->ITUmapping.insert(std::make_pair(L"\u0004\u00FA",L"["));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00FB",L"]"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00FC",L"."));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00DA",L"!"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00F9",L","));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00F1",L"/"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00E1",L")"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00E2",L"("));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00E9",L":"));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00A9",L" "));
	this->ITUmapping.insert(std::make_pair(L"\u0004\u00B4",L""));
	this->ITUmapping.insert(std::make_pair(L"\u0004 ",L" "));

}


void Converter::buildUTImapping()
{

//--------------------- These replacements should occurs first------------------------
						// See unicodeToInpage() function for detail

	this->UTImapping.insert(std::make_pair(L"\u06CC\u0626",L"\u0004\u00A4\u0004\u00BF"));
	this->UTImapping.insert(std::make_pair(L"\u0627\u0004\b",L"\u0004\u0081\u0004\b"));
	this->UTImapping.insert(std::make_pair(L"\u0623",L"\u0004\u0081\u0004\u00BF"));
	this->UTImapping.insert(std::make_pair(L"\u0624",L"\u0004\u00A2\u0004\u00BF"));
	this->UTImapping.insert(std::make_pair(L"\u0622",L"\u0004\u0081\u0004\u00B3"));
//---------------------------------------------------------------------------

	this->UTImapping.insert(std::make_pair(L"\u06BA",L"\u0004\u00A1"));
	this->UTImapping.insert(std::make_pair(L"\u064D",L"\u0004\u00A8"));
	this->UTImapping.insert(std::make_pair(L"\u06F1",L"\u0004\u00D1"));
	this->UTImapping.insert(std::make_pair(L"\u06F2",L"\u0004\u00D2"));
	this->UTImapping.insert(std::make_pair(L"\u06F3",L"\u0004\u00D3"));
	this->UTImapping.insert(std::make_pair(L"\u06F4",L"\u0004\u00D4"));
	this->UTImapping.insert(std::make_pair(L"\u06F5",L"\u0004\u00D5"));
	this->UTImapping.insert(std::make_pair(L"\u06F6",L"\u0004\u00D6"));
	this->UTImapping.insert(std::make_pair(L"\u06F7",L"\u0004\u00D7"));
	this->UTImapping.insert(std::make_pair(L"\u06F8",L"\u0004\u00D8"));
	this->UTImapping.insert(std::make_pair(L"\u06F9",L"\u0004\u00D9"));
	this->UTImapping.insert(std::make_pair(L"\u06F0",L"\u0004\u00D0"));
	this->UTImapping.insert(std::make_pair(L"\u0642",L"\u0004\u203A"));
	this->UTImapping.insert(std::make_pair(L"\u0648",L"\u0004\u00A2"));
	this->UTImapping.insert(std::make_pair(L"\u0639",L"\u0004\u02DC"));
	this->UTImapping.insert(std::make_pair(L"\u0631",L"\u0004\u017D"));
	this->UTImapping.insert(std::make_pair(L"\u062A",L"\u0004\u201E"));
	this->UTImapping.insert(std::make_pair(L"\u06D2",L"\u0004\u00A5"));
	this->UTImapping.insert(std::make_pair(L"\u0621",L"\u0004\u00A3"));
	this->UTImapping.insert(std::make_pair(L"\u06CC",L"\u0004\u00A4"));
	this->UTImapping.insert(std::make_pair(L"\u06C1",L"\u0004\u00A6"));
	this->UTImapping.insert(std::make_pair(L"\u067E",L"\u0004\u0192"));
	this->UTImapping.insert(std::make_pair(L"\u060E",L"\u0004\u00F2"));
	this->UTImapping.insert(std::make_pair(L"\u0627",L"\u0004\u0081"));
	this->UTImapping.insert(std::make_pair(L"\u0633",L"\u0004\u2019"));
	this->UTImapping.insert(std::make_pair(L"\u062F",L"\u0004\u2039"));
	this->UTImapping.insert(std::make_pair(L"\u0641",L"\u0004\u0161"));
	this->UTImapping.insert(std::make_pair(L"\u06AF",L"\u0004\u009D"));
	this->UTImapping.insert(std::make_pair(L"\u06BE",L"\u0004\u00A7"));
	this->UTImapping.insert(std::make_pair(L"\u062C",L"\u0004\u2021"));
	this->UTImapping.insert(std::make_pair(L"\u06A9",L"\u0004\u0153"));
	this->UTImapping.insert(std::make_pair(L"\u0644",L"\u0004\u017E"));
	this->UTImapping.insert(std::make_pair(L"\u061B",L"\u0004\u00EA"));
	this->UTImapping.insert(std::make_pair(L"\u0632",L"\u0004\u0090"));
	this->UTImapping.insert(std::make_pair(L"\u0634",L"\u0004\u201C"));
	this->UTImapping.insert(std::make_pair(L"\u0686",L"\u0004\u02C6"));
	this->UTImapping.insert(std::make_pair(L"\u0637",L"\u0004\u2013"));
	this->UTImapping.insert(std::make_pair(L"\u0628",L"\u0004\u201A"));
	this->UTImapping.insert(std::make_pair(L"\u0646",L"\u0004\u00A0"));
	this->UTImapping.insert(std::make_pair(L"\u0645",L"\u0004\u0178"));
	this->UTImapping.insert(std::make_pair(L"\u060C",L"\u0004\u00ED"));
	this->UTImapping.insert(std::make_pair(L"\u06D4",L"\u0004\u00F3"));
	this->UTImapping.insert(std::make_pair(L"\u064B",L"\u0004\u00C7"));
	this->UTImapping.insert(std::make_pair(L"\u064A",L"\u0004\u00B8"));
	this->UTImapping.insert(std::make_pair(L"\u0610",L"\u0004\u00F8"));
	this->UTImapping.insert(std::make_pair(L"\u0626",L"\u0004\u00A3"));
	this->UTImapping.insert(std::make_pair(L"\u064C",L"\u0004\u00B5"));
	this->UTImapping.insert(std::make_pair(L"\u0651",L"\u0004\u00AD"));
	this->UTImapping.insert(std::make_pair(L"\u0652",L"\u0004\u00B1"));
	this->UTImapping.insert(std::make_pair(L"\uFDFA",L"\u0004\u00F6"));
	this->UTImapping.insert(std::make_pair(L"\u0611",L"\u0004\u00AE"));
	this->UTImapping.insert(std::make_pair(L"\u0691",L"\u0004\u008F"));
	this->UTImapping.insert(std::make_pair(L"\u0679",L"\u0004\u2026"));
	this->UTImapping.insert(std::make_pair(L"\u0601",L"\u0004\u00F7"));
	this->UTImapping.insert(std::make_pair(L"\u0657",L"\u0004\u00BE"));
	this->UTImapping.insert(std::make_pair(L"\u0670",L"\u0004\u00BD"));
	this->UTImapping.insert(std::make_pair(L"\u06C3",L"\u0004\u00B9"));
	this->UTImapping.insert(std::make_pair(L"\u064F",L"\u0004\u00AC"));
	this->UTImapping.insert(std::make_pair(L"\u2018",L"\u0004\u00FD"));
	this->UTImapping.insert(std::make_pair(L"\u2019",L"\u0004\u00FE"));
	this->UTImapping.insert(std::make_pair(L"\u0614",L"\u0004\u00CF"));
	this->UTImapping.insert(std::make_pair(L"\u0653",L"\u0004\u00B3"));
	this->UTImapping.insert(std::make_pair(L"\u0635",L"\u0004\u201D"));
	this->UTImapping.insert(std::make_pair(L"\u0688",L"\u0004\u0152"));
	this->UTImapping.insert(std::make_pair(L"\u0656",L"\u0004\u00B0"));
	this->UTImapping.insert(std::make_pair(L"\u063A",L"\u0004\u2122"));
	this->UTImapping.insert(std::make_pair(L"\u062D",L"\u0004\u2030"));
	this->UTImapping.insert(std::make_pair(L"\u0636",L"\u0004\u2022"));
	this->UTImapping.insert(std::make_pair(L"\u062E",L"\u0004\u0160"));
	this->UTImapping.insert(std::make_pair(L"\u0612",L"\u0004\u00E7"));
	this->UTImapping.insert(std::make_pair(L"\u0630",L"\u0004\u008D"));
	this->UTImapping.insert(std::make_pair(L"\u0698",L"\u0004\u2018"));
	this->UTImapping.insert(std::make_pair(L"\u062B",L"\u0004\u2020"));
	this->UTImapping.insert(std::make_pair(L"\u0638",L"\u0004\u2014"));
	this->UTImapping.insert(std::make_pair(L"\u0613",L"\u0004\u00E6"));
	this->UTImapping.insert(std::make_pair(L"\u0650",L"\u0004\u00AA"));
	this->UTImapping.insert(std::make_pair(L"\u064E",L"\u0004\u00AB"));
	this->UTImapping.insert(std::make_pair(L"\u061F",L"\u0004\u00EE"));
	this->UTImapping.insert(std::make_pair(L"[",L"\u0004\u00FA"));
	this->UTImapping.insert(std::make_pair(L"]",L"\u0004\u00FB"));
	this->UTImapping.insert(std::make_pair(L".",L"\u0004\u00FC"));
	this->UTImapping.insert(std::make_pair(L"!",L"\u0004\u00DA"));
	this->UTImapping.insert(std::make_pair(L",",L"\u0004\u00F9"));
	this->UTImapping.insert(std::make_pair(L"/",L"\u0004\u00F1"));
	this->UTImapping.insert(std::make_pair(L")",L"\u0004\u00E1"));
	this->UTImapping.insert(std::make_pair(L"(",L"\u0004\u00E2"));
	this->UTImapping.insert(std::make_pair(L":",L"\u0004\u00E9"));
	//this->UTImapping.insert(std::make_pair(L" ",L"\u0004\u00A9"));
	this->UTImapping.insert(std::make_pair(L"",L"\u0004\u00B4"));
	this->UTImapping.insert(std::make_pair(L" ",L"\u0004 "));

}


/**
 * Converts single line or multi-line Inpage text to corresponding Unicode Urdu text
 *
 * @param inpageText Text taken from InPage document
 * @return std::wstring corresponding Urdu Unicode of 'inpageText'
 *
 */
std::wstring Converter::inpageToUnicode(std::wstring inpageText)
{
	/**
	 * Mapping for Alif mada from InPage to Urdu Unicode is (L"\u0004\u0081\u0004\u00B3"),L"\u0622");
	 * If we don't perform this replacement FIRST before entering the replacement loop ...
	 * then resultant Urdu Unicode would we get corrupt as we have mapping for \u0004\u0081 and u0004\u00B3 in the mapping table. See buildITUmapping()
	 *
	 * Therefore we must first perform replacement for those InPage Characters (key in ITUmapping) which have more than 2 characters
	 * We have to perform this step explicitly as std::map dosen't preserve insertion order
	 *
	 * Same procedure of unicodeToInpage() function
	 */

	inpageText = std::regex_replace(inpageText, std::wregex(L"\u0004\u00A4\u0004\u00BF"),L"\u06CC\u0626");
	//inpageText = std::regex_replace(inpageText, std::wregex(L"\u0004\u0081\u0004\b"),L"\u0627\u0004\b");
	inpageText = std::regex_replace(inpageText, std::wregex(L"\u0004\u0081\u0004\u00BF"),L"\u0623");
	inpageText = std::regex_replace(inpageText, std::wregex(L"\u0004\u00A2\u0004\u00BF"),L"\u0624");
	inpageText = std::regex_replace(inpageText, std::wregex(L"\u0004\u0081\u0004\u00B3"),L"\u0622");




	for(auto const &pair : this->ITUmapping)
	{
		inpageText = std::regex_replace(inpageText, std::wregex(pair.first),pair.second);
	}

	// Don't get confused with identifier name 'inpageText'
	// At this point variable 'inpageText' is completely replaced with Urdu Unicode Characters

	return inpageText;


}

/**
 * Converts single line or multi-line Urdu Unicode text to corresponding text in InPage
 *
 * @param urduUnicodeText Urdu Unicode text to be converted to corresponding Inpage text
 * @return std::wstring corresponding Inpage text of 'urduUnicodeText'
 *
 */
std::wstring Converter::unicodeToInpage(std::wstring urduUnicodeText)
{
	// see inpageToUnicode() for detail

	//this->UTImapping.insert(std::make_pair(L"\u0627\u0004\b",L"\u0004\u0081\u0004\b"));
	urduUnicodeText = regex_replace(urduUnicodeText, std::wregex(L"\u06CC\u0626"),L"\u0004\u00A4\u0004\u00BF");
	urduUnicodeText = regex_replace(urduUnicodeText, std::wregex(L"\u0627\u0004\b"),L"\u0004\u0081\u0004\b");

	std::wstring inpageText;
	for(wchar_t unicodeCharacter : urduUnicodeText)
		inpageText += getInpageCharacterFor(unicodeCharacter);

	return inpageText;
}

/**
 *  Helper method to get Inpage character for corresponding Unicode Urdu character
 *  This private method is used by unicodeToInpage()
 */
std::wstring Converter::getInpageCharacterFor(const wchar_t unicodeUrduCharacter)
{
	// convert wchar_t character to std::wstring
	std::wstring key(1,unicodeUrduCharacter);

	auto it = this->UTImapping.find( key );

	if( it != this->UTImapping.end())
		return it->second; // If key is found return corresponding value

	//If key is not found return back the same unicodeUrduCharacter
	return std::wstring(1,unicodeUrduCharacter);

}

