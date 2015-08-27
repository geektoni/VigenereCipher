using namespace std;
#include <iostream>
#include <fstream>
#include "vigenere.h" 

int main(int argc, char * argv[]) {
  generateMatrix("tabulaRecta.txt");
  if (argc == 4) {
    cryptText(argv[1], argv[2], argv[3]);
  } else {
    cout << "Usage: input.txt output.txt encryption_key" << endl;
    cout << "Exiting" << endl;
  }
  return 0; 
}
