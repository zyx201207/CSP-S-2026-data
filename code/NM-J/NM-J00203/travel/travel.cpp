#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int typ=0,okc=0;
string s1,s2;
int c1,c2;
int main()
{
    freopen("travel1.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2;
    int c1,c2;
    cin >>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout <<1;  okc=1;
    }
    else{   cout <<0;}
    if(s1[0]==s2[0] && s1[1]==s2[1] && okc==1){
            cout <<1;typ=1;}
    else{   cout <<0;}
    bool df[2]={0};
    if(s1[2]=='D' || s1[2]=='F'){ df[0]=1;}
    if(s2[2]=='D' || s2[2]=='F'){ df[1]=1;}
    if(df[0]==df[1]){ cout<<1;}
    else{cout <<0;}
    if(c1==c2 && (s1[2]+'1'==s2[1]||s1[2]-'1'==s2[1])){
        cout <<1;
    }
    else{cout <<0;}
    return 0;
}