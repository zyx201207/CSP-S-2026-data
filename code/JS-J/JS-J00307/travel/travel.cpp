#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;//ab:r cd:X
char s[5]={'A','B','C'};
char t[5]={'D','F'};
int r;
int x;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>a>>b>>c>>d;
    for (int i=0;i<3;i++)
    {
        if (b[2]==s[i]) r=0;
        if (d[2]==s[i]) x=0;
    }
    for (int i=0;i<2;i++)
    {
        if (b[2]==t[i]) r=1;
        if (d[2]==t[i]) x=1;
    }
    if (a[0]==c[0]&&a[1]==c[1])//tongyichexiang
    {
        cout<<1;
        if (b[0]==d[0]&&b[1]==d[1])//tongtipai
        {
            cout<<1;
            if (b[2]=='D'&&d[2]=='F')
            {
                cout<<11;
            }
            else if (b[2]=='F'&&d[2]=='D')
            {
                cout<<11;
            }
            else if (r==x)
            {
                cout<<1;
                if (b[2]=='A'&&d[2]=='B') cout<<1;
                else if (b[2]=='B'&&d[2]=='C') cout<<1;
                else if (b[2]=='B'&&d[2]=='A') cout<<1;
                else if (b[2]=='C'&&d[2]=='B') cout<<1;
                else cout<<0;
            }
            else {cout<<0;cout<<0;}
        }
        else {cout<<0;cout<<0;cout<<0;}
    }
    else {cout<<0;cout<<0;cout<<0;cout<<0;}


    return 0;
}
