#include <bits/stdc++.h>
using namespace std;
string n,m,d,k;
string s;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i=0;i<=3;i++)
    {
        s[i]='0';
    }
    cin>>n>>m>>d>>k;
    if(n==d)
    {
        s[0]='1';
    }
    if(m[0]==k[0]&&m[1]==k[1]&&s[0]=='1')
    {
        s[1]='1';
    }
    if('A'<=m[2]&&m[2]<='C'&&'A'<=k[2]&&k[2]<='C'&&s[1]=='1')
    {
        s[2]='1';
    }
    if('D'<=m[2]&&m[2]<='F'&&'D'<=k[2]&&k[2]<='F'&&s[1]=='1')
    {
        s[2]='1';
    }
    int u=m[2];
    int t=k[2];
    if(s[2]=='1'&&(u-t==1||t-u==1))
    {
        s[3]='1';
    }
    for(int i=0;i<=3;i++)
    {
        cout<<s[i];
    }
    return 0;
}
