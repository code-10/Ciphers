#include <bits/stdc++.h>

using namespace std;

string encrypt(string plaintext,int key)
{
    int p=plaintext.length();
    char encrypt_rail[key][p];

    int row=0,col=0;

    for(int i=0; i<key; i++)
    {
        for(int j=0; j<p; j++)
        {
            encrypt_rail[i][j]='_';
        }
    }

    bool direction=false;

    for(int i=0; i<p; i++)
    {
        if(row==0||row==key-1)
        {
            direction=!direction;
        }

        encrypt_rail[row][col] = plaintext[i];
        col++;

        direction ? row++ : row--;

    }

    string cipher="";

    for(int i=0; i<key; i++)
    {
        for(int j=0; j<p; j++)
        {
            cout<<encrypt_rail[i][j]<<" ";
            if(encrypt_rail[i][j]!='_')
                cipher+=encrypt_rail[i][j];
        }
        cout<<endl;
    }

    return cipher;

}

string decrypt(string ciphertext,int key)
{
    int c=ciphertext.length();
    char decrypt_rail[key][c];

    int row=0,col=0;

    for(int i=0; i<key; i++)
    {
        for(int j=0; j<c; j++)
        {
            decrypt_rail[i][j]='_';
        }
    }

    bool direction=false;

    for(int i=0; i<c; i++)
    {
        if(row==0||row==key-1)
        {
            direction=!direction;
        }

        decrypt_rail[row][col] = '*';
        col++;

        direction ? row++ : row--;

    }

    int index=0;
    for(int i=0; i<key; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(decrypt_rail[i][j]=='*')
            {
                decrypt_rail[i][j]=ciphertext[index++];
            }
        }
    }

    string plain="";

    direction=false;
    row=0;
    col=0;

    for(int i=0; i<c; i++)
    {
        if(row==0||row==key-1)
        {
            direction=!direction;
        }

        plain+=decrypt_rail[row][col];
        col++;

        direction ? row++ : row--;

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
    cout<<"\nKey used is : "<<key<<endl<<endl;
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

