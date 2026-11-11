#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,c;
    string b,d;
    cin>>a>>b>>c>>d;
    if(a[1]==c[1]&&a[0]==c[0])
    {
        cout<<1;
        if(b[0]==d[0]&&b[1]==d[1])
        {
            cout<<1;
            if(b[2]-'A'<=3&&d[2]-'A'<=3)
            {
                cout<<1;
                if(b[2]-'A'+1==d[2]-'A')
                {
                    cout<<1;
                }
                else
                {
                    cout<<0;
                }
            }
            else if(b[2]-'A'>=4&&d[2]-'A'>=4)
            {
                cout<<1;
                if(b[2]-'A'+2==d[2]-'A')
                {
                    cout<<1;
                }
                else
                {
                    cout<<0;
                    return 0;
                }
            }
            else
            {
                cout<<0;
                return 0;
            }
        }
        else
        {
            cout<<0;
        }
    }
    else
    {
        cout<<0;
    }
    return 0;
}
