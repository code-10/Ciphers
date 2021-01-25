#include <bits/stdc++.h>

using namespace std;

map<char,char> m = {{'A', 'Z'}, {'B', 'Y'}, {'C', 'X'}, {'D', 'W'},{'E', 'V'},
                    {'F', 'U'}, {'G', 'T'}, {'H', 'S'}, {'I', 'R'},{'J', 'Q'},
                    {'K', 'P'}, {'L', 'O'}, {'M', 'N'}, {'N', 'M'},{'O', 'L'},
                    {'P', 'K'}, {'Q', 'J'}, {'R', 'I'}, {'S', 'H'},{'T', 'G'},
                    {'U', 'F'}, {'V', 'E'}, {'W', 'D'}, {'X', 'C'},{'Y', 'B'},
                    {'Z', 'A'},
                    {'a', 'z'}, {'b', 'y'}, {'c', 'x'}, {'d', 'w'},{'e', 'v'},
                    {'f', 'u'}, {'g', 't'}, {'h', 's'}, {'i', 'r'},{'j', 'q'},
                    {'k', 'p'}, {'l', 'o'}, {'m', 'n'}, {'n', 'm'},{'o', 'l'},
                    {'p', 'k'}, {'q', 'j'}, {'r', 'i'}, {'s', 'h'},{'t', 'g'},
                    {'u', 'f'}, {'v', 'e'}, {'w', 'd'}, {'x', 'c'},{'y', 'b'},
                    {'z', 'a'}};


string encrypt(string plaintext)
{
    //$ is used for space

    string cipher="";

    for(int i=0;i<plaintext.size();i++)
    {
        if(plaintext[i]!=' '){
            cipher+=m[plaintext[i]];
        }
        else
        {
            cipher+='$';
        }
    }

    return cipher;

}

string decrypt(string ciphertext)
{

    string plain="";

    for(int i=0;i<ciphertext.size();i++)
    {
        if(ciphertext[i]!='$'){
            plain+=m[ciphertext[i]];
        }
        else
        {
            plain+=' ';
        }
    }

    return plain;

}



int main()
{
    string s;
    cout<<"Enter a string to Encrypt\n";
    getline(cin,s);
    string cipher = encrypt(s);
    cout<<"\nCipher text is : "<<cipher<<endl;
    cout<<endl;

    char ch;
    cout<<"do you want to decrypt? y/n \n";
    cin>>ch;
    cout<<endl;
    if(ch=='y')
    {
        string plaintext = decrypt(cipher);
        cout<<"decrypted text is : "<<plaintext<<endl;
    }


}

