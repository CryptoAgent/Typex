#ifndef TYP
#define TYP

string GetStr(){
string s;
cin>>s;
return s;
}

int GetLen(string s){
int l = 0;
for(int i = 0;s[i]!='\0';i++){
    l++;
}
return l;
}

#endif
