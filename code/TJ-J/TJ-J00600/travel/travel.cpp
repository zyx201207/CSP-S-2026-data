#include<iostream>
#include<cstring>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    char a='0',b='0',c='0',d='0';
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        a='1';
        if(s1.substr(0,2)==s2.substr(0,2)){
            b='1';
            if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))){
                c='1';
                if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='F'&&s2[2]=='D')){
                    d='1';
                }
            }
        }
    }
    cout<<a<<b<<c<<d<<endl;
    return 0;
}