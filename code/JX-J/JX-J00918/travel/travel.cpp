#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b;
    int c,d;
    cin>>c>>a>>d>>b;
    if(c==d)
    {
        cout<<1;
        if(a[0]==b[0] and a[1]==b[1])
        {
            cout<<1;
            if(a[2]<=67 and b[2]<=67 or a[2]>67 and b[2]>67)
            {
                cout<<1;
                if(a[2]+1==b[2] or a[2]-1==b[2])
                {
                    cout<<1;
                }
                else{
                    cout<<0;
                    return 0;
                }
            }
            else{
                cout<<0;
                cout<<0;
                return 0;
            }
        }
        else{
            cout<<0;
            cout<<0;
            cout<<0;
            return 0;
        }
    }
    else{
        cout<<0;
        cout<<0;
        cout<<0;
        cout<<0;
        return 0;
    }
    return 0;
}
