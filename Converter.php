<?php
/** 
 * auther Umer farooq
 * email : umerfarooq2383@gmail.com
 * 
*/
class Converter 
{
    private $unicodeToInpageMapping;
    private $inpageToUnicodeMapping;


    public function __construct()
    {
        $this->buidUnicodeToInpageMapping();
        $this->buildInpageToUnicodeMapping();
    }


    /** Converts single line Urdu text written in unicode to inpage. For multilined text call this method multiple times for each line
	 * @param string $unicodeText - Single line of urdu text written in unicode
     * @return string inpage text
	 */

    public function unicodeToInpage($unicodeText)
    {
        $inpageText = "";
        $unicodeTextArray = $this->str_split_unicode($unicodeText);

        foreach($unicodeTextArray as $unicodeCharacter)
        {
            if(array_key_exists($unicodeCharacter,$this->unicodeToInpageMapping))
                $inpageText .= $this->unicodeToInpageMapping[$unicodeCharacter];
            else // if we do not have any mapping for a given character, then we simple append this character to output unchanged
                $inpageText .= $unicodeCharacter;
        
        }
            
         return $inpageText;   
        
    }

    /** Converts single line Urdu text written in inpage document to unicode. For multilined text call this method multiple times for each line
	 * @param string $inpageText - Single line of urdu text written in inpage document
     * @return string unicode text
	 */

    public function inpageToUnicode($inpageText)
    {

        //Since each urdu unicode character is mapped to 2 characters in inpage document (("›"-->'ق')), therefore we have to read @param inpageText in chunks of two characters
        //Only Alif-mada 'آ' when copied from inpage gives 3 characters '³'.
		//To deal with this here is a simple trick. Replace '³' with 'آآ' (double Alif-mada or any two characters) and then map 'آآ' back to 'آ'

        $unicodeText = "";
        $inpageTextArray = $this->str_split_unicode(str_replace("³","آآ",$inpageText),2);

         /*Reading inpageText in chunks of consecutive two characters
         * for example urdu word 'تم' when copied from inpage give "„ں" (four characters) where 'ت' has value '„' and 'م' has value 'Ÿ'.
         * That is why we have to read copied inpage text in chunks of two consecutive characters so that it can be mapped to unicode urdu character
         */

        foreach($inpageTextArray as $inpageCharacter)
        {   
            if(array_key_exists($inpageCharacter,$this->inpageToUnicodeMapping))
                $unicodeText .= $this->inpageToUnicodeMapping[$inpageCharacter];
            else // if we do not have any mapping for a given character, then we simple append this character to output unchanged
                $unicodeText .= $inpageCharacter;
        }

        return $unicodeText;    
    }

    private function buildInpageToUnicodeMapping()
    {
        
        //adding more mappings here

        $this->inpageToUnicodeMapping = array(

                                    "«"=>"َ",
                                    "µ"=>"ٌ",
                                    "œ"=>"ک",
                                    "¢"=>"و",
                                    " "=>"ن",
                                    "Ÿ"=>"م",
                                    "ž"=>"ل",
                                    "›"=>"ق",
                                    "š"=>"ف",
                                    "™"=>"غ",
                                    "‘"=>"ژ",
                                    "˜"=>"ع",
                                    "—"=>"ظ",
                                    "–"=>"ط",
                                    "•"=>"ض",
                                    "”"=>"ص",
                                    "“"=>"ش",
                                    "’"=>"س",
                                    ""=>"ڑ",
                                    ""=>"ز",
                                    "Ž"=>"ر",
                                    ""=>"ذ",
                                    "‹"=>"د",
                                    "Š"=>"خ",
                                    "‰"=>"ح",
                                    "‡"=>"ج",
                                    "†"=>"ث",
                                    "é"=>":",
                                    "„"=>"ت",
                                    "Œ"=>"ڈ",
                                    "‚"=>"ب",
                                    ""=>"ا",
                                    "ˆ"=>"چ",
                                    "£"=>"ئ",
                                    "¶"=>"ؤ",
                                    "³"=>"آ",
                                    "£"=>"ء",
                                    "î"=>"؟",
                                    "ß"=>"/",
                                    "ƒ"=>"پ",
                                    "ê"=>"؛",
                                    "…"=>"ٹ",
                                    "ó"=>"۔",
                                    "ö"=>"ﷺ",
                                    "ۓ"=>"ۓ",
                                    "Ï"=>"ؔ",
                                    "¥"=>"ے",
                                    
                                    "ç"=>"ؒ", 
                                    "½"=>"ٰ",
                                    "®"=>"ؑ",
                                    " "=>" ",
                                    "ø"=>"ؐ",
                                    "¤"=>"ی",
                                    "ò"=>"؎",
                                    "í"=>"،",
                                    "¹"=>"ۃ",
                                    "¦"=>"ہ",
                                    "§"=>"ھ",
                                    "¡"=>"ں",
                                    "¾"=>"ٗ",
                                    "°"=>"ٖ",
                                    "±"=>"ْ",
                                    "­"=>"ّ",
                                    "ª"=>"ِ",
                                    ""=>"گ",
                                    "¬"=>"ُ",
                                    "ý"=>"'",
                                    "þ"=>"'",
                                    "آآ"=>"آ",
                                    "Ú"=>"!"

        );
    }

    private function buidUnicodeToInpageMapping()
    {
        $this->unicodeToInpageMapping = array(

                                    "َ"=>"«",
                                    "ٌ"=>"µ",
                                    "ک"=>"œ",
                                    "و"=>"¢",
                                    "ن"=>" ",
                                    "م"=>"Ÿ",
                                    "ل"=>"ž",
                                    "ق"=>"›",
                                    "ف"=>"š",
                                    "غ"=>"™",
                                    "ژ"=>"‘",
                                    "ع"=>"˜",
                                    "ظ"=>"—",
                                    "ط"=>"–",
                                    "ض"=>"•",
                                    "ص"=>"”",
                                    "ش"=>"“",
                                    "س"=>"’",
                                    "ڑ"=>"",
                                    "ز"=>"",
                                    "ر"=>"Ž",
                                    "ذ"=>"",
                                    "د"=>"‹",
                                    "خ"=>"Š",
                                    "ح"=>"‰",
                                    "ج"=>"‡",
                                    "ث"=>"†",
                                    ":"=>"é",
                                    "ت"=>"„",
                                    "ڈ"=>"Œ",
                                    "ب"=>"‚",
                                    "ا"=>"",
                                    "چ"=>"ˆ",
                                    "ئ"=>"£",
                                    "ؤ"=>"¶",
                                    "آ"=>"³",
                                    "ء"=>"£",
                                    "؟"=>"î",
                                    "/"=>"ß",
                                    "پ"=>"ƒ",
                                    "؛"=>"ê",
                                    "ٹ"=>"…",
                                    "۔"=>"ó",
                                    "ﷺ"=>"ö",
                                    "ۓ"=>"ۓ",
                                    "ؔ"=>"Ï",
                                    "ے"=>"¥",
                                    
                                    "ؒ"=>"ç",
                                    "ٰ"=>"½",
                                    "ؑ"=>"®",
                                    " "=>" ",
                                    "ؐ"=>"ø",
                                    "ی"=>"¤",
                                    "؎"=>"ò",
                                    "،"=>"í",
                                    "ۃ"=>"¹",
                                    "ہ"=>"¦",
                                    "ھ"=>"§",
                                    "ں"=>"¡",
                                    "ٗ"=>"¾",
                                    "ٖ"=>"°",
                                    "ْ"=>"±",
                                    "ّ"=>"­",
                                    "ِ"=>"ª",
                                    "گ"=>"",
                                    "ُ"=>"¬",
                                    "'"=>"ý",
                                    "'"=>"þ",
                                    "\""=>"ýý",
                                    "!"=> "Ú"


        );

        

    }

    private function str_split_unicode($str, $l = 0) {
        if ($l > 0) {
            $ret = array();
            $len = mb_strlen($str, "UTF-8");
            for ($i = 0; $i < $len; $i += $l) {
                $ret[] = mb_substr($str, $i, $l, "UTF-8");
            }
            return $ret;
        }
        return preg_split("//u", $str, -1, PREG_SPLIT_NO_EMPTY);
    }


}
