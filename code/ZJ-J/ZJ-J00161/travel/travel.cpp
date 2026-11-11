#include<bits/stdc++.h>
using namespace std;
string ca,sa,cb,sb;
signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>ca>>sa>>cb>>sb;
    if(ca==cb)
    {
        cout<<1;
        if(sa[0]==sb[0] && sa[1]==sb[1])
        {
            cout<<1;
            if((sa[2]<='C' && sb[2]<='C') || (sa[2]>='D' && sb[2]>='D'))
            {
                cout<<1;
                if(abs(sa[2]-sb[2])==1)cout<<1;
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}