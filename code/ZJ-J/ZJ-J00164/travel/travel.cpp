#include <bits/stdc++.h>
using namespace std;
#define int long long 
string c1,s1,c2,s2;
signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<"1";
        if(s1.substr(0,2)==s2.substr(0,2))
        {
            cout<<"1";
            int ss1=s1.back()-'A',ss2=s2.back()-'A';
            if((ss1<=2&&ss2<=2)||(ss1>2&&ss2>2))
            {
                cout<<"1";
                if(ss1>ss2)
                {
                    swap(ss1,ss2);
                }
                if(ss1+1==ss2)
                {
                    cout<<"1";
                }
                else
                {
                    cout<<"0";
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
