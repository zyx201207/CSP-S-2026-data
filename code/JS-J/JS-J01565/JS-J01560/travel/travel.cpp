#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool pd(char x,char y)
{
    if (x=='A'||x=='B'||x=='C')
        if (y=='A'||y=='B'||y=='C') return 1;
    if (x=='D'||x=='E')
        if (y=='D'||y=='E') return 1;
    return 0;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>a>>b>>c>>d;
    if (a==c)
    {
        cout<<1;
        if (b[0]==d[0]&&b[1]==d[1])
        {
            cout<<1;
            if (pd(b[2],d[2]))
            {
                cout<<1;
                if (abs(b[2]-d[2])==1) cout<<1;
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
