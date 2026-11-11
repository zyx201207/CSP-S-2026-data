#include<bits/stdc++.h>
using namespace std;
string c,s,cx,sx;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c>>s>>cx>>sx;
    int x=s[2];
    int y=sx[2];
    if(c==cx)cout<<1;
    else
    {
        cout<<0;
    }

    if(c==cx&&s[0]==sx[0]&&s[1]==sx[1])cout<<1;
    else
    {
        cout<<0;
    }

    if(c==cx&&s[0]==sx[0]&&s[1]==sx[1]&&((x<='C'&&y<='C')||(x>='D'&&y>='D')))cout<<1;
    else
    {
        cout<<0;
    }

    if(c==cx&&(s[0]==sx[0]&&s[1]==sx[1])&&(abs(x-y)==1||(x=='D'&&y=='F')||(x=='F'&&y=='D'))&&((x<='C'&&y<='C')||(x>='D'&&y>='D')))cout<<1;
    else
    {
        cout<<0;
    }
    return 0;
}
