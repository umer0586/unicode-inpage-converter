# unicode-inpage-converter
Unicode to inpage and inpage to unicode converter

JAVA

```java
 Converter converter = new Converter();
	
 System.out.println(converter.unicodeToInpage("اسلام علیکم"));
 System.out.println(converter.inpageToUnicode("’žŸ ˜ž¤œŸ"));
```


PHP

```php
  $converter = new Converter();
  
  echo $converter->unicodeToInpage("اسلام علیکم");
  echo $converter->inpageToUnicode("’žŸ ˜ž¤œŸ");
```


C#

```C#
  Converter converter = new Converter();
  
  Console.WriteLine(converter.UnicodeToInpage("اسلام علیکم"));
  Console.WriteLine(converter.InpageToUnicode("’žŸ ˜ž¤œŸ"));
```

	Note there are several bugs in current implementation which need to be fixed
