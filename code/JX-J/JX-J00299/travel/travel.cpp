#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int a,b,f;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    f=1;
    if(c1!=c2)f=0;
    for(int i=0;i<=1;i++){
        a=a*10+s1[i]-'0';
        b=b*10+s2[i]-'0';
    }
    if(f)cout<<"1";
    else {
        cout<<"0";
    }
    if(f&&a==b)cout<<"1";
    else {
        cout<<"0";
        f=0;
    }
    if(f&&s1[2]=='A'&&(s2[2]=='B'||s2[2]=='C'))cout<<"1";
    else if(f&&s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C'))cout<<"1";
    else if(f&&s1[2]=='C'&&(s2[2]=='A'||s2[2]=='B'))cout<<"1";
    else if(f&&s1[2]=='D'&&s2[2]=='F')cout<<"1";
    else if(f&&s1[2]=='F'&&s2[2]=='D')cout<<"1";
    else {
        cout<<"0";
        f=0;
    }
    if(f&&abs(s1[2]-s2[2])==1)cout<<"1";
    else {
        cout<<"0";
    }
    return 0;
}