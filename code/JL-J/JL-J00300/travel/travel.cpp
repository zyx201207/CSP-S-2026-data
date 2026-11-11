#include<bits/stdc++.h>
using namespace std;

int a,b;
string s1,s2;
int p1,p2;
bool f1,f2,f3,f4;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>>a>>s1>>b>>s2;

    if(a==b) f1=true;


    if(f1 && s1[0]==s2[0] && s1[1]==s2[1]) f2=true;


    if(f1 && f2 && s1[2]<='C' && s2[2]<='C'){
        f3=true;
        if((s1[2]=='A' && s2[2]=='B') || (s1[2]=='B' && s2[2]=='A')) f4=true;
        else if((s1[2]=='B' && s2[2]=='C') || (s1[2]=='C' && s2[2]=='B')) f4=true;

    }else if(f1 && f2 && s1[2]>='D' && s2[2]>='D'){
        f3=true;
        if((s1[2]=='D' && s2[2]=='F') || (s1[2]=='F' && s2[2]=='D')) f4=true;
    }

    cout<<f1<<f2<<f3<<f4;
    return 0;
}
