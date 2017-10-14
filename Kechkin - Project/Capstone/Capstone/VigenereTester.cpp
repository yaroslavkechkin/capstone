//Copyright 2012 Yaroslav Kechkin
//Distributed under the terms of the GNU General Public License

//This file is part of Capstone.
//
//  Capstone is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  Capstone is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with Capstone.  If not, see <http://www.gnu.org/licenses/>.


#include "Vigenere.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <set>
#include <algorithm>
#include <iomanip>

using namespace std;


// CONSTRUCTOR

Vigenere :: Vigenere() 
	{
		inputText = "";
		outputText = "";
		key = "";
	}


// ACCESSOR GET

string Vigenere :: getInputText() 
	{
		return inputText;
	}

string Vigenere :: getOutputText() 
	{
		return outputText;
	}

string Vigenere :: getKey() 
	{
		return key;
	}

// ACCESSOR SET

void Vigenere :: setInputText(string newInputtext) 
	{
		inputText = newInputtext;
	}

void Vigenere :: setOutputText(string newOutputText)
	{
		outputText = newOutputText;
	}

void Vigenere :: setKey(string newKey)
	{
		key = newKey;
	}





void Vigenere :: inputKey() 
	{

		cout << "Input Key : ";
		getline(cin,key);
		getline(cin,key);

	}

void Vigenere :: inputAutoKey()
	{
		int n;		
		int k;
		cout << "Input the number for length of the key: ";
		cin >> n;
		string keyarray;
		srand(time(0));
		for (k = 0; k < n; k++)
			keyarray += rand()%256;
		key = keyarray;
	}

string Vigenere :: getRepeatKey()
	{
		string output = "";
		int i = 0;

		while (output.length() != inputText.length()) {		
			output += key[i];
			i++;
			if (i == key.length()) {
				i = 0;
			}
		}
		cout << "Key becomes : " << output << "\n";
		return output;
	}


void Vigenere :: encryptKey() 
	{
		int k;
		string keyRepeated = getRepeatKey();
		for (k=0; k < inputText.length(); k++) 
			{
				outputText += (char)((int)inputText[k]+(int)keyRepeated[k])%256;
			}
	}

void Vigenere :: encryptAutoKey()
	{				
		int i = 0;
		string keyRepeated = getRepeatKey();

		for (i=0; i < inputText.length(); i++) 
			{
				outputText += (char)((int)inputText[i]+(int)keyRepeated[i])%256;
			}
	}

void Vigenere :: decryptKey()
	{
		string keyRepeated = getRepeatKey();
		
		for (int i=0; i<inputText.length(); i++) 
			{
				outputText += (char)((int)inputText[i]-(int)keyRepeated[i])%256;
				
				if ((int)outputText[0] < 0) 
					{
						outputText[0] += 256;
					}				
			}
	}

void Vigenere :: decryptAutoKey() 
	{
		ifstream akey;	
		string fileString = "";
		string tempString = "";

		printf("\nInput key file name: ");
		cin >> fileString;		
		akey.open(fileString.c_str());

		if (!akey) {
			cout << "Can't open the file. \n";            
			cin.sync();
			cin.get();
			exit(1);
		}

		akey >> noskipws;

		int i = 0;
		while (!akey.eof())
			{
				getline (akey, key);
			}

		key = key.substr(0,key.length());
		akey.close();

		string keyRepeated = getRepeatKey();
		
		for (int i=0; i<inputText.length(); i++) 
			{
				outputText += (char)((int)inputText[i]-(int)keyRepeated[i])%256;
				
				if ((int)outputText[0] < 0) 
					{
						outputText[0] += 256;
					}				
			}
	}

void Vigenere :: inputDisplay()
	{
		cout << "\n\n==> DISPLAY INPUT\n\n";
		cout << inputText;
		cout << "\n\n";
	}

void Vigenere :: outputDisplay() 
	{
		cout << "\n\n==> DISPLAY OUTPUT\n\n";
		cout << outputText;
		cout << "\n\n";
	}

void Vigenere :: inputFile() 
	{
		ifstream input;	
		string fileString = "";
		string tempString = "";

		printf("\nInput file name: ");
		cin >> fileString;		
		input.open(fileString.c_str());

		if (!input) {
			cout << "Can't open the file. \n";            
			cin.sync();
			cin.get();
			exit(1);
		}

		input >> noskipws;

		int i = 0;
		while (!input.eof())
			{
				getline (input, inputText);
			}

		inputText = inputText.substr(0,inputText.length());
		input.close();
	}

void Vigenere :: outputFileEncrypt() 
	{
		ofstream output;
		output.open("outputEncrypt.txt");

		output << outputText;

		cout << "> Output has been saved into outputEncrypt.txt\n";

		output.close();
	}

void Vigenere :: outputFileEncryptAutoKey()
	{
		ofstream output;
		output.open("outputEncryptAutoKey.txt");

		output << outputText;

		cout << "> Output has been saved into outputEncryptAutoKey.txt\n";

		output.close();

		output.open("outputAutoKey.txt");

		output << key;

		cout << "> Key has been saved into outputAutoKey.txt\n";

		output.close();
	}

void Vigenere :: outputFileDecrypt() 
	{
		ofstream output;
		output.open("outputDecrypt.txt");

		output << outputText;

		cout << "> Output has been saved into outputDecrypt.txt\n";

		output.close();
	}

void Vigenere :: outputFileDecryptAutoKey() 
	{
		ofstream output;
		output.open("outputDecryptAutoKey.txt");

		output << outputText;

		cout << "> Output has been saved into outputDecryptAutoKey.txt\n";

		output.close();
	}


void Vigenere :: menu()
	{
		string index = "";
		while (index != "5") {
			cout << "\n\n==> MENU\n\n";
			cout << "1. Encrypt\n";
			cout << "2. Encrypt with Auto-Key\n";
			cout << "3. Decrypt with Key\n";
			cout << "4. Decrypt with Auto-Key\n";
			cout << "5. Exit \n";
			cout << "\n> Select a number : ";
			cin >> index;
		
		
			if (index.length() == 1) 
				{
					switch((int)index[0]) 
						{
							case ((int)'1'): 
					
											inputFile();
											inputDisplay();
											inputKey();
											encryptKey(); 
											outputDisplay();
											outputFileEncrypt();
											index = "5";
											system("PAUSE");
											break;

							case ((int)'2'): 
											inputFile();
											inputDisplay();
											inputAutoKey();
											encryptAutoKey(); 
											outputDisplay();
											outputFileEncryptAutoKey();
											index = "5";
											system("PAUSE");
											break;

							case ((int)'3'): 
											inputFile();
											inputDisplay();
											inputKey();
											decryptKey(); 
											outputDisplay();
											outputFileDecrypt();
											index = "5";				
											system("PAUSE");
											break;

							case ((int)'4'): 
											inputFile();
											inputDisplay();											
											decryptAutoKey(); 
											outputDisplay();
											outputFileDecryptAutoKey();
											system("PAUSE");
											index = "5";				
											break;		

							case ((int)'5'):
											break;

							default: 	
											cout << "Invalid Input \n \n";
											index = "0";
				
						}	//end switch


				} 
		
		
			else 
				{
					cout << "Invalid Input \n \n";
					index = "0";
				}

		}	//end while


	}