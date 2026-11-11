#include<bits/stdc++.h>
using namespace std;
string s;
int c1,c2,s1,s2;
char cs1,cs2;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        c1=c1*10+s[i]-'0';
    }
    cin>>s;
    cs1=s[s.size()-1];
    for(int i=0;i<s.size()-1;i++)
    {
        s1=s1*10+s[i]-'0';
    }
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        c2=c2*10+s[i]-'0';
    }
    cin>>s;
    cs2=s[s.size()-1];
    for(int i=0;i<s.size()-1;i++)
    {
        s2=s2*10+s[i]-'0';
    }
    //cout<<c1<<" "<<s1<<cs1<<" "<<c2<<" "<<s2<<cs2<<"\n";
    if(c1==c2)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    if(s1==s2 && c1==c2)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    if(s1==s2 && c1==c2 && ((cs1<='C' && cs1>='A' && cs2>='A' && cs2<='C') || (cs1<='E' && cs1>='D' && cs2>='D' && cs2<='E')))
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    if(s1==s2 && c1==c2 && ((cs1<='C' && cs1>='A' && cs2>='A' && cs2<='C') || (cs1<='E' && cs1>='D' && cs2>='D' && cs2<='E')) && ((cs1=='C' && cs2=='B') || (cs2=='A' && cs1=='B') || (cs2=='C' && cs1=='B') || (cs1=='A' && cs2=='B') || (cs1=='E' && cs2=='D') || (cs1=='D' && cs2=='E')))
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    return 0;
}
