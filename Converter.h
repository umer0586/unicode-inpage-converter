/**
 * Author
 * 	Umer Farooq
 */

#ifndef CONVERTER_H_
#define CONVERTER_H_

#include<map>
#include<string>

class Converter {

private:
	std::map<std::wstring , std::wstring> UTImapping;
	std::map<std::wstring , std::wstring> ITUmapping;

	std::wstring getInpageCharacterFor(const wchar_t unicodeUrduCharacter);
private:
	void buildUTImapping();
	void buildITUmapping();

public:
	Converter();
	std::wstring inpageToUnicode(std::wstring inpageText);
	std::wstring unicodeToInpage(std::wstring unicodeText);

};

#endif /* CONVERTER_H_ */
