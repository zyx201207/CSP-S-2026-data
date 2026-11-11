#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string q,w,e,r;
    cin>>q>>w>>e>>r;
    if(q==e)
    {
        cout<<"1";
        if(w[0]==r[0]&&w[1]==r[1])
        {
            cout<<"1";
            if((w[2]+1==r[2]&&w[2]!='C')||(w[2]-1==r[2]&&w[2]!='D'))
            {
                cout<<"11";
            }
            else if((w[2]=='A'&&r[2]=='C')||(w[2]=='C'&&r[2]=='A'))
            {
                cout<<"10";
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
