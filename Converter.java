// author - umer farooq
// email - umerfarooq2383@gmail.com

import java.util.Hashtable;



public class Converter
{
	private Hashtable<Character, String> unicodeToInpageMappings;
	private Hashtable<String, Character> inpageToUnicodeMappings;

	public Converter()
	{
       buildUnicodeToInpageMapping();
       buildInpageToUnicodeMapping();
           
	}
	
	/** Converts single line Urdu text written in unicode to inpage. For multilined text call this method multiple times for each line
	 * @param unicodeText - Single line of urdu text written in unicode
	 * @return Inpage text 
	 */
	
	public String unicodeToInpage(String unicodeText)
	{
			
		String inpageText = "";
		
		
		for(char unicodeCharacter : unicodeText.toCharArray())
		{
			
			if(unicodeToInpageMappings.containsKey(unicodeCharacter))	
				inpageText += unicodeToInpageMappings.get(unicodeCharacter);
			else // if we do not have any mapping for a given character, then we simple append this character to output unchanged
				inpageText += unicodeCharacter;
	
		}
		
		return inpageText;
	}
	
	/** Converts single line Urdu text written in inpage document to unicode. For multilined text call this method multiple times for each line
	 * @param inpageText - Single line of urdu text written in inpage document
	 * @return unicode text
	 */
	
	public String inpageToUnicode(String inpageText)
	{
	
		//Since each urdu unicode character is mapped to 2 characters in inpage document (("›"-->'ق')), therefore we have to read @param inpageText in chunks of two characters
		
		String unicodeText = "";
		
		
		//Only Alif-mada 'آ' when copied from inpage gives 3 characters '³'.
		//To deal with this here is a simple trick. Replace '³' with 'آآ' (double Alif-mada or any two characters) and then map 'آآ' back to 'آ'
		String newtext = inpageText.replaceAll("³", "آآ");
		
        char inpageCharArray[] = newtext.toCharArray();
        
        
        /*Reading inpageText in chunks of consecutive two characters
         * for example urdu word 'تم' when copied from inpage give "„ں" (four characters) where 'ت' has value '„' and 'م' has value 'Ÿ'.
         * That is why we have to read copied inpage text in chunks of two consecutive characters so that it can be mapped to unicode urdu character
         */
		
		int even = 0;
		int odd = 1;
		for (int i = 0; i < inpageCharArray.length; i++)
		{
			if(even > inpageCharArray.length-1 || odd > inpageCharArray.length-1)
				break;
			
			String inpageCharacter = inpageCharArray[even] +""+inpageCharArray[odd] ;
			
			even += 2;
			odd += 2;
			
			if(inpageToUnicodeMappings.containsKey(inpageCharacter))
				unicodeText += inpageToUnicodeMappings.get(inpageCharacter);
			else // if we do not have any mapping for a given character, then we simple append this character to output unchanged
				unicodeText += inpageCharacter;
			
		}
		
		return unicodeText;
	}
	

	//you can add more mappings here if needed
	private void buildUnicodeToInpageMapping()
	{
	
		
		
		unicodeToInpageMappings = new Hashtable<>();
		
		unicodeToInpageMappings.put('ق',"›");
		unicodeToInpageMappings.put('و',"¢");
		unicodeToInpageMappings.put('ع',"˜");
		unicodeToInpageMappings.put('ر',"Ž");
		unicodeToInpageMappings.put('ت',"„");
		unicodeToInpageMappings.put('ے',"¥");
		unicodeToInpageMappings.put('ئ',"£");
		unicodeToInpageMappings.put('ی',"¤");
		unicodeToInpageMappings.put('ہ',"¦");
		unicodeToInpageMappings.put('پ',"ƒ");
		unicodeToInpageMappings.put('ٌ',"µ");
		unicodeToInpageMappings.put('ْ',"±");
		unicodeToInpageMappings.put('؎',"ò");
		unicodeToInpageMappings.put('ا',"");
		unicodeToInpageMappings.put('س',"’");
		unicodeToInpageMappings.put('د',"‹");
		unicodeToInpageMappings.put('ف',"š");
		unicodeToInpageMappings.put('گ',"");
		unicodeToInpageMappings.put('ھ',"§");
		unicodeToInpageMappings.put('ج',"‡");
		unicodeToInpageMappings.put('ک',"œ");
		unicodeToInpageMappings.put('ل',"ž");
		unicodeToInpageMappings.put('؛',"ê");
		//mapping.put('\'',"'");
		unicodeToInpageMappings.put('ز',"");
		unicodeToInpageMappings.put('ش',"“");
		unicodeToInpageMappings.put('چ',"ˆ");
		unicodeToInpageMappings.put('ط',"–");
		unicodeToInpageMappings.put('ب',"‚");
		unicodeToInpageMappings.put('ن'," ");
		unicodeToInpageMappings.put('م',"Ÿ");
		unicodeToInpageMappings.put('،',"í");
		unicodeToInpageMappings.put('۔',"ó");
		unicodeToInpageMappings.put('/',"ß");
		unicodeToInpageMappings.put('ﷺ',"ö");
		unicodeToInpageMappings.put('ؤ',"¶");
		unicodeToInpageMappings.put('ؑ',"®");
		unicodeToInpageMappings.put('ڑ',"");
		unicodeToInpageMappings.put('ٹ',"…");
		unicodeToInpageMappings.put('ۓ',"ۓ");
		unicodeToInpageMappings.put('ء',"£");
		unicodeToInpageMappings.put('ٰ',"½");
		unicodeToInpageMappings.put('ۃ',"¹");
		unicodeToInpageMappings.put('ُ',"¬");
		unicodeToInpageMappings.put('ٗ',"¾");
		unicodeToInpageMappings.put('ّ',"­");
		unicodeToInpageMappings.put('ؔ',"Ï");
		unicodeToInpageMappings.put('آ',"³");
		unicodeToInpageMappings.put('ص',"”");
		unicodeToInpageMappings.put('ڈ',"Œ");
		unicodeToInpageMappings.put('ٖ',"°");
		unicodeToInpageMappings.put('غ',"™");
		unicodeToInpageMappings.put('ح',"‰");
		unicodeToInpageMappings.put('ض',"•");
		unicodeToInpageMappings.put('خ',"Š");
		unicodeToInpageMappings.put('ؒ',"ç");
		unicodeToInpageMappings.put(':',"é");
		unicodeToInpageMappings.put('"',"''");
		unicodeToInpageMappings.put('ذ',"");
		unicodeToInpageMappings.put('ژ',"‘");
		unicodeToInpageMappings.put('ث',"†");
		unicodeToInpageMappings.put('ظ',"—");
		unicodeToInpageMappings.put('ں',"¡");
		unicodeToInpageMappings.put('ؐ',"ø");
		unicodeToInpageMappings.put('ِ',"ª");
		unicodeToInpageMappings.put('َ',"«");
		unicodeToInpageMappings.put('؟',"î");
		unicodeToInpageMappings.put(' '," ");
		unicodeToInpageMappings.put('!', "Ú");


		
	}
	
	//You can add more mappings here if needed
	private void buildInpageToUnicodeMapping()
	{
		
		inpageToUnicodeMappings = new Hashtable<>();
		 
		inpageToUnicodeMappings.put("›",'ق');
		inpageToUnicodeMappings.put("¢",'و');
		inpageToUnicodeMappings.put("˜",'ع');
		inpageToUnicodeMappings.put("Ž",'ر');
		inpageToUnicodeMappings.put("„",'ت');
		inpageToUnicodeMappings.put("¥",'ے');
		inpageToUnicodeMappings.put("£",'ئ');
		inpageToUnicodeMappings.put("¤",'ی');
		inpageToUnicodeMappings.put("¦",'ہ');
		inpageToUnicodeMappings.put("ƒ",'پ');
		inpageToUnicodeMappings.put("µ",'ٌ');
		inpageToUnicodeMappings.put("±",'ْ');
		inpageToUnicodeMappings.put("ò",'؎');
		inpageToUnicodeMappings.put("",'ا');
		inpageToUnicodeMappings.put("’",'س');
		inpageToUnicodeMappings.put("‹",'د');
		inpageToUnicodeMappings.put("š",'ف');
		inpageToUnicodeMappings.put("",'گ');
		inpageToUnicodeMappings.put("§",'ھ');
		inpageToUnicodeMappings.put("‡",'ج');
		inpageToUnicodeMappings.put("œ",'ک');
		inpageToUnicodeMappings.put("ž",'ل');
		inpageToUnicodeMappings.put("ê",'؛');
		//mapping.put("'",'\'');
		inpageToUnicodeMappings.put("",'ز');
		inpageToUnicodeMappings.put("“",'ش');
		inpageToUnicodeMappings.put("ˆ",'چ');
		inpageToUnicodeMappings.put("–",'ط');
		inpageToUnicodeMappings.put("‚",'ب');
		inpageToUnicodeMappings.put(" ",'ن');
		inpageToUnicodeMappings.put("Ÿ",'م');
		inpageToUnicodeMappings.put("í",'،');
		inpageToUnicodeMappings.put("ó",'۔');
		inpageToUnicodeMappings.put("ß",'/');
		inpageToUnicodeMappings.put("ö",'ﷺ');
		inpageToUnicodeMappings.put("¶",'ؤ');
		inpageToUnicodeMappings.put("®",'ؑ');
		inpageToUnicodeMappings.put("",'ڑ');
		inpageToUnicodeMappings.put("…",'ٹ');
		inpageToUnicodeMappings.put("ۓ",'ۓ');
		inpageToUnicodeMappings.put("£",'ء');
		inpageToUnicodeMappings.put("½",'ٰ');
		inpageToUnicodeMappings.put("¹",'ۃ');
		inpageToUnicodeMappings.put("¬",'ُ');
		inpageToUnicodeMappings.put("¾",'ٗ');
		inpageToUnicodeMappings.put("­",'ّ');
		inpageToUnicodeMappings.put("Ï",'ؔ');
		inpageToUnicodeMappings.put("³",'آ');
		inpageToUnicodeMappings.put("”",'ص');
		inpageToUnicodeMappings.put("Œ",'ڈ');
		inpageToUnicodeMappings.put("°",'ٖ');
		inpageToUnicodeMappings.put("™",'غ');
		inpageToUnicodeMappings.put("‰",'ح');
		inpageToUnicodeMappings.put("•",'ض');
		inpageToUnicodeMappings.put("Š",'خ');
		inpageToUnicodeMappings.put("ç",'ؒ');
		inpageToUnicodeMappings.put("é",':');
		inpageToUnicodeMappings.put("''",'"');
		inpageToUnicodeMappings.put("",'ذ');
		inpageToUnicodeMappings.put("‘",'ژ');
		inpageToUnicodeMappings.put("†",'ث');
		inpageToUnicodeMappings.put("—",'ظ');
		inpageToUnicodeMappings.put("¡",'ں');
		inpageToUnicodeMappings.put("ø",'ؐ');
		inpageToUnicodeMappings.put("ª",'ِ');
		inpageToUnicodeMappings.put("«",'َ');
		inpageToUnicodeMappings.put("î",'؟');
		inpageToUnicodeMappings.put(" ",' ');
		inpageToUnicodeMappings.put("آآ", 'آ');
		inpageToUnicodeMappings.put("Ú", '!');
		

		
	}
	


}
