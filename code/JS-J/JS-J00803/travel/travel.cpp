#include<bits/stdc++.h>
using namespace std;
string ri,rr,xi,xr;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>ri>>rr>>xi>>xr;
    if(ri==xi)
    {
        cout<<1;
        if(rr.substr(0,2)==xr.substr(0,2))
        {
            cout<<1;
            if(rr[2]<='C'&&xr[2]<='C')
            {
                cout<<1;
                if(abs((int)rr[2]-xr[2])==1)
                    cout<<1;
                else
                    cout<<0;
            }
            else if(rr[2]>='D'&&xr[2]>='D')
                cout<<"11";
            else
                cout<<"00";
        }
        else
            cout<<"000";
    }
    else
        cout<<"0000";
}
