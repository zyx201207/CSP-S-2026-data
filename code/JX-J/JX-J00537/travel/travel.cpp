#include<bits/stdc++.h>
using namespace std;
int n,m;
string k,l;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n>>k>>m>>l;
    if(n==m)
    {
        cout<<1;
        if(k[0]==l[0]&&k[1]==l[1])
        {
            cout<<1;
            if(k[2]<'D'&&l[2]<'D')
            {
                cout<<1;
                if(k[2]=='B')
                {
                    cout<<1;
                }
                else if(l[2]=='B')
                {
                    cout<<1;
                }
                else{
                    cout<<0;
                }
            }
            else if(k[2]>'C'&&l[2]>'C')
            {
                cout<<"11";
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}
