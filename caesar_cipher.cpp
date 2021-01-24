#include <bits/stdc++.h>

using namespace std;

string encrypt(string plaintext,int key)
{
    string cipher="";
    int p=plaintext.size();

    for (int i=0;i<p;i++)
    {
        if (isupper(plaintext[i]))
            cipher += char(plaintext[i]+key-65%26 +65);
        else
            cipher += char(int(plaintext[i]+key-97)%26 +97);
    }

    return cipher;

}

string decrypt(string ciphertext,int key)
{
    string plain="";
    int c=ciphertext.size();

    for (int i=0;i<c;i++)
    {
        if (isupper(ciphertext[i]))
            plain += char(ciphertext[i]-key-65%26 +65);
        else
            plain += char(int(ciphertext[i]-key-97)%26 +97);
    }

    return plain;


}

int main()
{
    srand((unsigned) time(0));
    string s;
    cout<<"Enter a string to Encrypt\n";
    cin>>s;
    int key = (rand() % (5 - 2 + 1)) + 2;
    cout<<"\nKey used is : "<<key<<endl;
    string cipher = encrypt(s,key);
    cout<<"\nCipher text is : "<<cipher<<endl;
    cout<<endl;

    char ch;
    cout<<"do you want to decrypt? y/n \n";
    cin>>ch;
    if(ch=='y')
    {
        string plaintext = decrypt(cipher,key);
        cout<<"\ndecrypted text is : "<<plaintext<<endl;
    }


}


