#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    int s11,s21;
    s11=s1[0]*10+s1[1];
    s21=s2[0]*10+s2[1];
    char s12=s1[2],s22=s2[2];
    if(c1==c2)
        cout<<1;
    else
        cout<<0;
    if(c1==c2 && s11==s21)
        cout<<1;
    else
        cout<<0;
    if(c1==c2 && s11==s21 && (((s12>='A' && s12<='C') && (s22>='A' && s22<='C')) || ((s12>='D' && s12<='F') && (s22>='D' && s22<='F'))))
        cout<<1;
    else
        cout<<0;
    if(c1==c2 && s11==s21 && (((s12>='A' && s12<='C') && (s22>='A' && s22<='C')) || ((s12>='D' && s12<='F') && (s22>='D' && s22<='F'))) && abs(s12-s22)<=1)
        cout<<1;
    else
        cout<<0;
    return 0;
}
