#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a[0]==c[0]&&a[1]==c[1])cout<<"1";
    else
    {
        cout<<"0000";
        return 0;
    }
    if(b[0]==d[0]&&b[1]==d[1])cout<<"1";
    else
    {
        cout<<"000";
        return 0;
    }
    int x=b[2]-'A';
    int y=d[2]-'A';
    if(x<=2&&y<=2)
    {
        if(abs(x-y)==1)cout<<"11";
        else cout<<"10";
        return 0;
    }
    if(x>2&&y>2)
    {
        cout<<"11";
        return 0;
    }
    else cout<<"00";
    return 0;
}
