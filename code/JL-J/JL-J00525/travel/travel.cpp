#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,e="",f="";
char j,s;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>a>>b>>c>>d;
    if(a==c)cout<<1;
    else
    {
        cout<<"0000";
        return 0;
    }
    e+=b[0];
    e+=b[1];
    f+=d[0];
    f+=d[1];
    if(e==f)cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    j=b[2];
    s=d[2];
    if(j=='A'||j=='B'||j=='C')
    {
        if(s=='C'||s=='A'||s=='B') cout<<1;
        else
        {
            cout<<"00";
            return 0;
        }
    }
    if(j=='D'||j=='E')
    {
        if(s=='D'||s=='E') cout<<1;
        else
        {
            cout<<"00";
            return 0;
        }
    }
    if(j+1==s||j-1==s)
    {
        cout<<1;
    }
    else{
        cout<<0;
    }
    return 0;
}





