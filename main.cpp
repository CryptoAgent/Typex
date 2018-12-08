#include <iostream>
#include <stdlib.h>
using namespace std;
#include "TYP.h"

int Rotors[3][26]={0};
char p1[5]={'a','f','d','c','e'};
char p2[5]={'g','r','j','h','u'};

int main(){
cout<<"Please enter message\r\n>";
string mess = GetStr();
int m_len = GetLen(mess);
cout<<"\r\nEnter rotors position:\r\n";
int rotors[3];
for(int i = 0;i<3;i++){
    cin>>rotors[i];
}
cout<<"Enter key position for every rotor:\r\n";
int key_pos[3];
for(int i = 0;i<3;i++){
    int k = 0;
    cin>>k;
    k%=26;
    key_pos[i]=k;
}
for(int i = 0;i<3;i++){
    for(int j = 0;j<26;j++){
        int k = rand();
        k%=26;
        Rotors[i][j]=k;
    }
}
string enc1;
for(int i = 0;i<m_len;i++){
    char ch = mess[i];
    int summ=Rotors[rotors[0]][key_pos[0]]+Rotors[rotors[1]][key_pos[1]]+Rotors[rotors[2]][key_pos[2]];
    ch-=97;
    ch+=summ;
    ch%=26;
    ch+=97;
    enc1+=ch;
    if(key_pos[2]<25){
        key_pos[2]=key_pos[2]+1;
    }else{
        key_pos[2]=0;
        if(key_pos[1]<25){
            key_pos[1]=key_pos[1]+1;
        }else{
            key_pos[1]=0;
            if(key_pos[0]<25){
                key_pos[0]=key_pos[0]+1;
            }else{
                key_pos[0]=0;
            }
        }
    }
}
string enc2;
for(int i = 0;i<m_len;i++){
    char ch = enc1[i];
    for(int j = 0;j<5;j++){
        if(ch==p1[j]){
            ch=p2[j];
        }
    }
    enc2+=ch;
}
cout<<"Your encrypted message is: ";
cout<<enc2<<endl;
//Decryption
cout<<"Please enter message\r\n>";
mess = GetStr();
m_len = GetLen(mess);
cout<<"\r\nEnter rotors position:\r\n";
for(int i = 0;i<3;i++){
    cin>>rotors[i];
}
cout<<"Enter key position for every rotor:\r\n";
for(int i = 0;i<3;i++){
    int k = 0;
    cin>>k;
    k%=26;
    key_pos[i]=k;
}
string dec1;
for(int i = 0;i<m_len;i++){
    char ch = mess[i];
    for(int j = 0;j<5;j++){
        if(ch==p2[j]){
            ch=p1[j];
        }
    }
    dec1+=ch;
}
string dec2;
for(int i = 0;i<m_len;i++){
    char ch = dec1[i];
    int summ=Rotors[rotors[0]][key_pos[0]]+Rotors[rotors[1]][key_pos[1]]+Rotors[rotors[2]][key_pos[2]];
    ch-=97;
    ch-=summ;
    while(ch<0){
        ch+=26;
    }
    ch+=97;
    dec2+=ch;
    if(key_pos[2]<25){
        key_pos[2]=key_pos[2]+1;
    }else{
        key_pos[2]=0;
        if(key_pos[1]<25){
            key_pos[1]=key_pos[1]+1;
        }else{
            key_pos[1]=0;
            if(key_pos[0]<25){
                key_pos[0]=key_pos[0]+1;
            }else{
                key_pos[0]=0;
            }
        }
    }
}
cout<<dec2;
return 0;
}
