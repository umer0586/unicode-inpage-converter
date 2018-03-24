// author - umer farooq
// email - umerfarooq2383@gmail.com

class Converter {

        private Dictionary<char, string> unicodeToInpageMapping;
        private Dictionary<string, char> inpageToUnicodeMapping;

        public Converter()
        {
            BuildUnicodeToInpageMapping();
            BuildInpageToUnicodeMapping();
        }

        /// <summary>
        /// Converts single line Urdu text written in unicode to inpage. For multilined text call this method multiple times for each line 
        /// </summary>
        /// <returns>
        /// Inpage text
        /// </returns>
        /// <param name="unicodeText">Single line of urdu text written in unicode</param>

        public string UnicodeToInpage(string unicodeText)
        {
            string inpageText = "";
            

            foreach (char unicodeCharacter in unicodeText.ToCharArray())
            {
                if (unicodeToInpageMapping.ContainsKey(unicodeCharacter))
                    inpageText += unicodeToInpageMapping[unicodeCharacter];
                else //if we do not have any mapping for a given character, then we simple append this character to output unchanged
                    inpageText += unicodeCharacter;
            }

            return inpageText;

        }

        private void BuildUnicodeToInpageMapping()
        {
            unicodeToInpageMapping = new Dictionary<char, string>();

            unicodeToInpageMapping['َ'] = "«";
            unicodeToInpageMapping['ٌ'] = "µ";
            unicodeToInpageMapping['ک'] = "œ";
            unicodeToInpageMapping['و'] = "¢";
            unicodeToInpageMapping['ن'] = " ";
            unicodeToInpageMapping['م'] = "Ÿ";
            unicodeToInpageMapping['ل'] = "ž";
            unicodeToInpageMapping['ق'] = "›";
            unicodeToInpageMapping['ف'] = "š";
            unicodeToInpageMapping['غ'] = "™";
            unicodeToInpageMapping['ژ'] = "‘";
            unicodeToInpageMapping['ع'] = "˜";
            unicodeToInpageMapping['ظ'] = "—";
            unicodeToInpageMapping['ط'] = "–";
            unicodeToInpageMapping['ض'] = "•";
            unicodeToInpageMapping['ص'] = "”";
            unicodeToInpageMapping['ش'] = "“";
            unicodeToInpageMapping['س'] = "’";
            unicodeToInpageMapping['ڑ'] = "";
            unicodeToInpageMapping['ز'] = "";
            unicodeToInpageMapping['ر'] = "Ž";
            unicodeToInpageMapping['ذ'] = "";
            unicodeToInpageMapping['د'] = "‹";
            unicodeToInpageMapping['خ'] = "Š";
            unicodeToInpageMapping['ح'] = "‰";
            unicodeToInpageMapping['ج'] = "‡";
            unicodeToInpageMapping['ث'] = "†";
            unicodeToInpageMapping[':'] = "é";
            unicodeToInpageMapping['ت'] = "„";
            unicodeToInpageMapping['ڈ'] = "Œ";
            unicodeToInpageMapping['ب'] = "‚";
            unicodeToInpageMapping['ا'] = "";
            unicodeToInpageMapping['چ'] = "ˆ";
            unicodeToInpageMapping['ئ'] = "£";
            unicodeToInpageMapping['ؤ'] = "¶";
            unicodeToInpageMapping['آ'] = "³";
            unicodeToInpageMapping['ء'] = "£";
            unicodeToInpageMapping['؟'] = "î";
            unicodeToInpageMapping['/'] = "ß";
            unicodeToInpageMapping['پ'] = "ƒ";
            unicodeToInpageMapping['؛'] = "ê";
            unicodeToInpageMapping['ٹ'] = "…";
            unicodeToInpageMapping['۔'] = "ó";
            unicodeToInpageMapping['ﷺ'] = "ö";
            unicodeToInpageMapping['ۓ'] = "ۓ";
            unicodeToInpageMapping['ؔ'] = "Ï";
            unicodeToInpageMapping['ے'] = "¥";
            unicodeToInpageMapping['"'] = "''";
            unicodeToInpageMapping['ؒ'] = "ç";
            unicodeToInpageMapping['ٰ'] = "½";
            unicodeToInpageMapping['ؑ'] = "®";
            unicodeToInpageMapping[' '] = " ";
            unicodeToInpageMapping['ؐ'] = "ø";
            unicodeToInpageMapping['ی'] = "¤";
            unicodeToInpageMapping['؎'] = "ò";
            unicodeToInpageMapping['،'] = "í";
            unicodeToInpageMapping['ۃ'] = "¹";
            unicodeToInpageMapping['ہ'] = "¦";
            unicodeToInpageMapping['ھ'] = "§";
            unicodeToInpageMapping['ں'] = "¡";
            unicodeToInpageMapping['ٗ'] = "¾";
            unicodeToInpageMapping['ٖ'] = "°";
            unicodeToInpageMapping['ْ'] = "±";
            unicodeToInpageMapping['ّ'] = "­";
            unicodeToInpageMapping['ِ'] = "ª";
            unicodeToInpageMapping['گ'] = "";
            unicodeToInpageMapping['ُ'] = "¬";
            unicodeToInpageMapping['!'] = "Ú";


        }

        private void BuildInpageToUnicodeMapping()
        {
            inpageToUnicodeMapping = new Dictionary<string, char>();
            inpageToUnicodeMapping[" "] = 'ن';
            inpageToUnicodeMapping[""] = 'گ';
            inpageToUnicodeMapping["…"] = 'ٹ';
            inpageToUnicodeMapping["ø"] = 'ؐ';
            inpageToUnicodeMapping["•"] = 'ض';
            inpageToUnicodeMapping["ö"] = 'ﷺ';
            inpageToUnicodeMapping["‡"] = 'ج';
            inpageToUnicodeMapping["†"] = 'ث';
            inpageToUnicodeMapping["œ"] = 'ک';
            inpageToUnicodeMapping["Œ"] = 'ڈ';
            inpageToUnicodeMapping["ó"] = '۔';
            inpageToUnicodeMapping["„"] = 'ت';
            inpageToUnicodeMapping["ò"] = '؎';
            inpageToUnicodeMapping["آآ"] = 'آ';
            inpageToUnicodeMapping["”"] = 'ص';
            inpageToUnicodeMapping["“"] = 'ش';
            inpageToUnicodeMapping[""] = 'ز';
            inpageToUnicodeMapping["î"] = '؟';
            inpageToUnicodeMapping[""] = 'ڑ';
            inpageToUnicodeMapping["‚"] = 'ب';
            inpageToUnicodeMapping["’"] = 'س';
            inpageToUnicodeMapping["í"] = '،';
            inpageToUnicodeMapping["‘"] = 'ژ';
            inpageToUnicodeMapping[""] = 'ذ';
            inpageToUnicodeMapping["ˆ"] = 'چ';
            inpageToUnicodeMapping["ê"] = '؛';
            inpageToUnicodeMapping["é"] = ':';
            inpageToUnicodeMapping["—"] = 'ظ';
            inpageToUnicodeMapping["ç"] = 'ؒ';
            inpageToUnicodeMapping["–"] = 'ط';
            inpageToUnicodeMapping[""] = 'ا';
            inpageToUnicodeMapping["ß"] = '/';
            inpageToUnicodeMapping[" "] = ' ';
            inpageToUnicodeMapping["™"] = 'غ';
            inpageToUnicodeMapping["ƒ"] = 'پ';
            inpageToUnicodeMapping["³"] = 'آ';
            inpageToUnicodeMapping["Ï"] = 'ؔ';
            inpageToUnicodeMapping["ۓ"] = 'ۓ';
            inpageToUnicodeMapping["ž"] = 'ل';
            inpageToUnicodeMapping["Ž"] = 'ر';
            inpageToUnicodeMapping["¾"] = 'ٗ';
            inpageToUnicodeMapping["½"] = 'ٰ';
            inpageToUnicodeMapping["Ÿ"] = 'م';
            inpageToUnicodeMapping["¹"] = 'ۃ';
            inpageToUnicodeMapping["¶"] = 'ؤ';
            inpageToUnicodeMapping["µ"] = 'ٌ';
            inpageToUnicodeMapping["±"] = 'ْ';
            inpageToUnicodeMapping["°"] = 'ٖ';
            inpageToUnicodeMapping["›"] = 'ق';
            inpageToUnicodeMapping["''"] = '"';
            inpageToUnicodeMapping["®"] = 'ؑ';
            inpageToUnicodeMapping["‹"] = 'د';
            inpageToUnicodeMapping["­"] = 'ّ';
            inpageToUnicodeMapping["¬"] = 'ُ';
            inpageToUnicodeMapping["«"] = 'َ';
            inpageToUnicodeMapping["ª"] = 'ِ';
            inpageToUnicodeMapping["§"] = 'ھ';
            inpageToUnicodeMapping["¦"] = 'ہ';
            inpageToUnicodeMapping["‰"] = 'ح';
            inpageToUnicodeMapping["¥"] = 'ے';
            inpageToUnicodeMapping["¤"] = 'ی';
            inpageToUnicodeMapping["£"] = 'ء';
            inpageToUnicodeMapping["š"] = 'ف';
            inpageToUnicodeMapping["Š"] = 'خ';
            inpageToUnicodeMapping["¢"] = 'و';
            inpageToUnicodeMapping["˜"] = 'ع';
            inpageToUnicodeMapping["¡"] = 'ں';
            inpageToUnicodeMapping["Ú"] = '!';
            
        }

        /// <summary>
        /// Converts single line Urdu text written in unicode to inpage. For multilined text call this method multiple times for each line 
        /// </summary>
        /// <returns>
        /// Unicode text
        /// </returns>
        /// <param name="inpageText">Single line of urdu text written in inpage document/param>

        public string InpageToUnicode(string inpageText)
        {
            //Since each urdu unicode character is mapped to 2 characters in inpage document (("›"-->'ق')), therefore we have to read @param inpageText in chunks of two characters
            string unicodeText = "";

            //Only Alif-mada 'آ' when copied from inpage gives 3 characters '³'.
            //To deal with this here is a simple trick. Replace '³' with 'آآ' (double Alif-mada or any two characters) and then map 'آآ' back to 'آ'
            string newtext = inpageText.Replace("³", "آآ");

            char[] inpageCharArray = newtext.ToCharArray();

           /* Reading inpageText in chunks of consecutive two characters
            * for example urdu word 'تم' when copied from inpage give "„ں" (four characters) where 'ت' has value '„' and 'م' has value 'Ÿ'.
            * That is why we have to read copied inpage text in chunks of two consecutive characters so that it can be mapped to unicode urdu character
            */

            int even = 0;
            int odd = 1;
            for (int i = 0; i < inpageCharArray.Length; i++)
            {
                if (even > inpageCharArray.Length - 1 || odd > inpageCharArray.Length - 1)
                    break;

                string inpageCharacter = inpageCharArray[even] + "" + inpageCharArray[odd];

                even += 2;
                odd += 2;

                if (inpageToUnicodeMapping.ContainsKey(inpageCharacter))
                    unicodeText += inpageToUnicodeMapping[inpageCharacter];
                else //if we do not have any mapping for a given character, then we simple append this character to output unchanged
                    unicodeText += inpageCharacter;

            }

            return unicodeText;

        }
        

    }