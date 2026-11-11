#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    int a1,a2,b1,b2;
    char a3,b3;
    cin>>a1>>a2>>a3>>b1>>b2>>b3;
    if(a3=='F')a3='E';
    if(b3=='F')b3='E';
    if(a1==b1)cout<<1;
    else
    {
        cout<<"0000";
        return 0;
    }
    if(a2==b2)cout<<1;
    else
    {
        cout<<"000";
        return 0;
    }
    if((a3>='A'&&a3<='C'&&b3>='A'&&b3<='C')||(a3>='D'&&a3<='E'&&b3>='D'&&b3<='E'))cout<<1;
    else
    {
        cout<<"00";
        return 0;
    }
    if(a3==b3-1||a3==b3+1)cout<<1;
    else cout<<0;
    return 0;
}
