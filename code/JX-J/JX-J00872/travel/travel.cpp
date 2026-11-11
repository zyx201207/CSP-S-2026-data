#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    int x=(a[0]-'0')*10+(a[1]-'0');
    int y=(c[0]-'0')*10+(c[1]-'0');
    if(x==y) cout<<1;
    else
    {
        cout<<"0000";
        return 0;
    }
    int q=(b[0]-'0')*10+(b[1]-'0');
    int w=(d[0]-'0')*10+(d[1]-'0');
    if(q==w) cout<<1;
    else
    {
        cout<<"000";
        return 0;
    }
    if(b[2]<='C'&&d[2]<='C') cout<<1;
    else if(b[2]<='F'&&d[2]<='F'&&b[2]>'C'&&d[2]>'C') cout<<1;
    else
    {
        cout<<"00";
        return 0;
    }
    int e=b[2]-'0';
    int r=d[2]-'0';
    int t=e;
    e=min(t,r);
    r=max(t,r);
    t=r-e;
    if(t==1) cout<<1;
    else cout<<0;
    return 0;
}
