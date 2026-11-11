#include <bits/stdc++.h>
using namespace std;
#define int long long
string s1,s2;
int c1,c2,a1,a2;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<1;
        if(s1[0]==s2[0]&&s1[1]==s2[1])
        {
            cout<<1;
            a1=s1[2]-'A';
            a2=s2[2]-'A';
            if(a1>=0&&a1<=2&&a2>=0&&a2<=2||
               a1==3&&a2==4||a1==4&&a2==3)
            {
                cout<<1;
                if(abs(a1-a2)==1)
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
                cout<<0;
                cout<<0;
            }
        }
        else
        {
            cout<<0;
            cout<<0;
            cout<<0;
        }
    }
    else
    {
        cout<<0;
        cout<<0;
        cout<<0;
        cout<<0;
    }
    return 0;
}
