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


#include <string>


using namespace std;

class Vigenere
{
	private:
		
		string inputText;						// input text 
		string outputText;						// output text 
		string key;								// key to encrypt/decrypt between plaintext and ciphertext
		

		
	public:
		
		Vigenere();								// construct Vigenere instance


		// ACCESSOR GET

		string getInputText(); 					//returns inputText value 

		string getOutputText();					// returns outputText value 

		string getKey(); 						// return key value



		// ACCESSOR SET

		void setInputText(string);				// changes inputText value 

		void setOutputText(string);				// changes outputText value

		void setKey(string);					// changes key value

		


		// METHOD

		void menu();							// displays command menu

		void inputKey();						// inputs key for encryption / decryption 

		void inputAutoKey();

		string getRepeatKey();					// returns repeated key with length equals plaintext's length

		void encryptKey();						// encrypts plaintext using key

		void encryptAutoKey();					// encrypts plaintext using key with Auto-Key mode

		void decryptKey();						// decrypts ciphertext using key

		void decryptAutoKey();					// decrypts ciphertext using key with Auto-Key mode

		void inputDisplay();					// display input

		void outputDisplay();					// display output

		void inputFile();						// reads input from a file 

		void outputFileEncrypt();				// writes ciphertext output into a file (outputEncrypt.txt)

		void outputFileEncryptAutoKey();		// writes ciphertext (with auto-key) output into a file (outputEncryptAutoKey.txt)

		void outputFileDecrypt();				// writes plaintext output into a file (outputDecrypt.txt)

		void outputFileDecryptAutoKey();		// writes plaintext (with auto-key) output into a file (outputDecryptAutoKey.txt)


};