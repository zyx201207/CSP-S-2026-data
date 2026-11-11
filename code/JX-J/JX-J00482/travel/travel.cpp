#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool b=0,c=0,d=0,e=0;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) {b=1;}
    if(b==1&&s1[0]==s2[0]&&s1[1]==s2[1])
    {
        c=1;
    }
    if(c==1)
    {
        if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')
        {
            d=1;
        }
        if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')
        {
            d=1;e=1;
        }
    }
    if(d==1)
    {
        if(s1[2]=='A'&&s2[2]=='B') e=1;
        if(s1[2]=='B'&&s2[2]=='C') e=1;
        if(s2[2]=='A'&&s1[2]=='B') e=1;
        if(s2[2]=='B'&&s1[2]=='C') e=1;
    }
    if(b==1) cout<<1; else cout<<0;
    if(c==1) cout<<1; else cout<<0;
    if(d==1) cout<<1; else cout<<0;
    if(e==1) cout<<1; else cout<<0;
    fclose(stdin);fclose(stdout);
    return 0;
}
