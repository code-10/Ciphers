#include <bits/stdc++.h>

using namespace std;

string encrypt(string plaintext,string key)
{
    string cipher="";

    while(plaintext.length()>key.length())
        key+=key;

    for(int i=0;i<plaintext.size();i++)
    {

        cipher += (((plaintext[i] - '0') ^ (key[i] - '0')) + '0');

    }

    return cipher;

}

string decrypt(string ciphertext,string key)
{

    string plain="";

    while(ciphertext.length()>key.length())
        key+=key;

    for(int i=0;i<ciphertext.size();i++)
    {

        plain += (((ciphertext[i] - '0') ^ (key[i] - '0')) + '0');

    }


    return plain;

}

int main()
{
    srand((unsigned) time(0));
    string s,key;
    cout<<"Enter a string to Encrypt\n";
    getline(cin,s);
    cout<<"Enter the key\n";
    getline(cin,key);
    string cipher = encrypt(s,key);
    cout<<"\nCipher text is : "<<cipher<<endl;
    cout<<endl;

    char ch;
    cout<<"do you want to decrypt? y/n \n";
    cin>>ch;
    cout<<endl;
    if(ch=='y')
    {
        string plaintext = decrypt(cipher,key);
        cout<<"\ndecrypted text is : "<<plaintext<<endl;
    }


}
