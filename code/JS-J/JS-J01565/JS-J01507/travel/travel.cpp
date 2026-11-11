#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string x,xx,y,yy;
    cin>>x>>xx>>y>>yy;
    if(x!=y)
    {
        cout<<"0000";
        return 0;
    }
    else
    {
        string xx2=xx.substr(0,2);
        string yy2=yy.substr(0,2);
        if(xx2!=yy2)
        {
            cout<<"1000";
            return 0;
        }
        else
        {
            int k=xx[2]-'A',k2=yy[2]-'A';
            k=min(k,4);
            k2=min(k2,4);
            if((k<=2&&k2>=3)||(k>=3&&k2<=2))
            {
                cout<<"1100";
                return 0;
            }
            else
            {
                if(abs(k-k2)>1) cout<<"1110";
                else cout<<"1111";
            }
        }
    }
    return 0;
}
