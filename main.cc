using namespace std;
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "vigenere.h" 

int main(int argc, char * argv[]) {
  
  char c; 
 
  /* Check if there are enough arguments */
  if (argc == 4) {
    cout << "Decrypt or Encrypt (d/e): ";
    cin >> c;
    switch(c) {
      case 'e':
        /* Encrypt text */
        cryptText(argv[1], argv[2], argv[3]);
      break;
      case 'd':
        /* Decrypt text */
        decryptText(argv[1], argv[2], argv[3]);
      break;
      default:
        /* Exit if are supplied wrong letter */
        cout << "I didn't understand. Exiting";
        exit(1);
      break;  
    }
  } else {
    cout << "Usage: <input> <output> <encryption_key>" << endl;
    cout << "Exiting" << endl;
  }
  return 0; 
}
