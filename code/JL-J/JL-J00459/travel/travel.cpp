#include <bits/stdc++.h>
using namespace std;
string x,y,c,s;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>x>>y>>c>>s;
    if(x==c)
    {
        cout<<1;
        if(y[0]==s[0] && y[1]==s[1])
        {
            cout<<1;
            if((y[2]<'D'&&s[2]<'D') || (y[2]>='D'&&s[2]>='D'))
            {
                cout<<1;
                if(abs(y[2]-s[2])==1 && y[2]<'D'&&s[2]<'D')
                    cout<<1;
                else if(y[2]>='D'&&s[2]>='D')
                    cout<<1;
                else
                    cout<<0;
            }
            else
            {
                cout<<0<<0;
                return 0;
            }

        }
        else
        {
            cout<<0<<0<<0;
            return 0;
        }

    }
    else
    {
        cout<<0<<0<<0<<0;
        return 0;
    }
    return 0;
}
