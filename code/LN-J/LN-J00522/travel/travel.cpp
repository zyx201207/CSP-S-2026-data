#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,dd;
    cin>>a>>b>>c>>dd;
    if(a==c) cout<<1;
    else{
        cout<<0<<0<<0<<0;
        return 0;
    }
    if(b[0]==dd[0]&&b[1]==dd[1])
    {
        cout<<1;
        if((b[2]=='A'&&dd[2]=='B')||(b[2]=='B'&&dd[2]=='C')||(b[2]=='B'&&dd[2]=='A')||(b[2]=='C'&&dd[2]=='B')||(b[2]=='A'&&dd[2]=='C')||(b[2]=='C'&&dd[2]=='A')||(b[2]=='D'&&dd[2]=='F')||(b[2]=='F'&&dd[2]=='D'))
        {
            cout<<1;
            if((b[2]=='A'&&dd[2]=='B')||(b[2]=='B'&&dd[2]=='C')||(b[2]=='B'&&dd[2]=='A')||(b[2]=='C'&&dd[2]=='B')||(b[2]=='D'&&dd[2]=='F')||(b[2]=='F'&&dd[2]=='D'))
            {
                cout<<1;
            }else{
                cout<<0;
                return 0;
            }
        }else{
            cout<<0<<0;
            return 0;
        }
    }else{
        cout<<0<<0<<0;
        return 0;
    }
    return 0;
}
