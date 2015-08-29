using namespace std;
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "vigenere.h" 

int main(int argc, char * argv[]) {
  char fileName[] = "tabulaRecta";
  generateTabula(fileName);
  if (argc == 4) {
    char c;
    cout << "Decrypt or Encrypt (d/e): ";
    cin >> c;
    switch(c) {
      case 'e':
        cryptText(argv[1], argv[2], argv[3]);
      break;
      case 'd':
        decryptText(argv[1], argv[2], argv[3]);
      break;
      default:
        cout << "I didn't understand. Exiting";
        exit(1);
      break;  
    }
  } else {
    cout << "Usage: input.txt output.txt encryption_key" << endl;
    cout << "Exiting" << endl;
  }
  return 0; 
}
