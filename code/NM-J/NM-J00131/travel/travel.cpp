#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,c1,c2;
    char a='0',b='0',c='0',d='0';
    cin>>s1>>c1>>s2>>c2;
    if (s1==s2)
        a='1';
    string sh1,sh2;
    char z1,z2;
    for (int i=0;i<c1.size();i++)
        if (c1[i]>='0'&&c1[i]<='9')
            sh1+=c1[i];
        else
            z1=c1[i];
    for (int i=0;i<c2.size();i++)
        if (c2[i]>='0'&&c2[i]<='9')
            sh2+=c2[i];
        else
            z2=c2[i];
    if (a=='1'&&sh1==sh2)
        b='1';
    if (b=='1'&&(z1=='A'||z1=='B'||z1=='C'))
        if (z2=='A'||z2=='B'||z2=='C')
            c='1';
        else
            c='0';
    else if (b=='1'&&(z1=='D'||z2=='F'))
        if (z2=='D'||z2=='F')
            c='1';
        else
            c='0';
    if(a=='1'&&b=='1'&&c=='1'&&( (z1=='A'&&z2=='B') || (z1=='B'&&(z2=='A'||z2=='C')) || (z1=='C'&&z2=='B') || (z1=='D'&&z2=='F')))
            d='1';
    cout<<a<<b<<c<<d;
    return 0;
}
