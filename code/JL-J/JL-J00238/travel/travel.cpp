#include<bits/stdc++.h>
using namespace std;
string r,x,a,b;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>r>>a>>x>>b;
    if(r==x)
    {
        cout<<"1";
        if(a[0]==b[0]&&a[1]==b[1])
        {
            cout<<"1";
            if((a[2]<='C'&&b[2]<='C')||(a[2]>'C'&&b[2]>'C'))
            {
                cout<<"1";
                if((a[2]=='C'&&b[2]=='A')||(a[2]=='A'&&b[2]=='C'))
                {
                    cout<<"0";
                }
                else
                {
                    cout<<"1";
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
