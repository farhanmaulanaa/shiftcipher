/*
Nama      : Farhan Maulana Alief
NPM       : 140810190073
Kelas     : A
Deskripsi : Shift Cipher Enkripsi dan Dekripsi
*/

#include <bits/stdc++.h>
using namespace std;

string enkripsi(string PlainText, int key)
{
  string CipherText = "";
  for (int i = 0; i < PlainText.size(); i++)
  {
    if (isupper(PlainText[i]))
    {
      CipherText += char(int(PlainText[i] + key - 65) % 26 + 65);
    }
    else
    {
      CipherText += char((int(PlainText[i] + key - 97) % 26) + 97);
    }
  }
  return CipherText;
}

string dekripsi(string CipherText, int key) 
{
  string PlainText = "";
  for (int i = 0; i < CipherText.size(); i++)
  {
    if (isupper(CipherText[i]))
    {
      PlainText += char((int(CipherText[i] - key - 65) % 26 + 26) % 26 + 65);
    }
    else
    {
      PlainText += char((int(CipherText[i] - key - 97) % 26) + 97);
    }
  }
  return PlainText;
}

int main()
{
  bool isLoop = true;
  char x;
  while (isLoop == true)
  {
    string PlainText;
    cout << endl;
    cout << "Input Plainteks: ";

    getline(cin, PlainText);
    int key;
    cout << "Input Kunci: ";
    cin >> key;
    cout << "...............................................\n";

    string CipherText = enkripsi(PlainText, key);
    string plain_Text = dekripsi(CipherText, key);

    cout << "Enkripsi: " << CipherText;
    cout << "\nDekripsi: " << plain_Text;
    cout << "\n...............................................\n";
    do
    {
      cout << "\nStart Program(y/n)? ";
      cin >> x;
      cin.ignore();
      if (x == 'y' || x == 'Y')
      {
        isLoop = true;
      }
      else if (x == 'n' || x == 'N')
      {
        isLoop = false;
      }
    } while (x != 'y' && x != 'Y' && x != 'n' && x != 'N');
  }
}