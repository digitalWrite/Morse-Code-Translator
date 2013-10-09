	/********** Name: Morse Code Translator 
	 **********	Description: translates from the English alphabet to the Morse code alphabet through the serial monitor  
	 **********	Author: Ross - http://www.rossboswellprojects.co.uk
	 ********** Hardware: Connect a led to pin 12, leds typically require a 150ohms to 220ohms resister 
	 **********/
	
	
	
	#define ledPin 12
	#define timeDelay 150

	char* digit[] = {
	  "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};
	  
	char* letter[] = {
	  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",    // A-I
	  ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",  // J-R
	  "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."          // S-Z
	};

	
	void setup()                 
	{
	  pinMode(ledPin, OUTPUT);
	  Serial.begin(9600);
	}

	void flashSuccession(char* succession)
	{
	  int i = 0;
	  
	  while (succession[i] != '\0')
	  {
		  flashDeOrDah(succession[i]);
		  i++;
	  }
	 
	}

	void flashDeOrDah(char dotOrDash)
	{
	  digitalWrite(ledPin, HIGH);
	  if (dotOrDash == '.')
	  {
		  delay(timeDelay);           
	  }
	  else 
	  {
		  delay(timeDelay * 3);           
	  }
	  digitalWrite(ledPin, LOW);    
	  
	  delay(timeDelay); // space after individual flashes 
	}
	
	void loop()                    
	{
	  char c;
	  if (Serial.available() > 0)
	  {
		  c = Serial.read();
		  if (c >= 'a' && c <= 'z')
		  {
		    flashSuccession(letter[c - 'a']);
	          }
		  else if (c >= 'A' && c <= 'Z')
		  {
		    flashSuccession(letter[c - 'A']);
		  }
		
		else if (c >= '0' && c <= '9')
		{
		  flashSuccession(digit[c - '0']);
		}
		
		else if (c == ' ') // generates space between words
		{
		  delay(timeDelay * 3);  
		}
	  }
	}
