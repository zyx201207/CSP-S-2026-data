#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,a1,a2;
int main()
{
freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    a1+=s1[0]+s1[1];
    a2+=s2[0]+s2[1];
    if(c1!=c2)cout<<"0000";
    else if(a1!=a2)cout<<"1000";
    else if(!(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'||s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'))
    cout<<"1100";
    else if(!(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='C'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D'))
    cout<<"1110";
    else cout<<"1111";
    return 0;
}
