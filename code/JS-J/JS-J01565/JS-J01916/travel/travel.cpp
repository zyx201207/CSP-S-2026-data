#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string cx1,cx2,zw1,zw2;
    cin>>cx1>>zw1>>cx2>>zw2;
    if(cx1==cx2)
    {
        cout<<1;
        if(zw1[0]==zw2[0]&&zw1[1]==zw2[1])
        {
            cout<<1;
            if(zw1[2]<='C'&&zw2[2]<='C'||zw1[2]>='D'&&zw2[2]>='D')
            {
                cout<<1;
                if(abs(zw1[2]-zw2[2])==1||zw1[2]=='D'&&zw2[2]=='F'||zw1[2]=='F'&&zw2[2]=='D')
                {
                    cout<<1;
                }
                else
                {
                    cout<<0;
                }
            }
            else
            {
                cout<<"00";
            }
        }
        else
        {
            cout<<"000";
        }
    }
    else
    {
        cout<<"0000";
    }
    return 0;
}
