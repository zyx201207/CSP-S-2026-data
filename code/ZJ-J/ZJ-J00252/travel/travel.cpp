#include<bits/stdc++.h>
#define int long long
using namespace std;

string c1,s1,c2,s2;
int l1;
char i1;
int l2;
char i2;

signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    sscanf(s1.c_str(),"%lld%c",&l1,&i1);
    sscanf(s2.c_str(),"%lld%c",&l2,&i2);
    if(c1 == c2)
    {
        cout<<"1";
        if(l1 == l2)
        {
            cout<<"1";
            if(
            i1 == 'A' && i2 == 'B' ||
            i1 == 'A' && i2 == 'C' ||
            i1 == 'B' && i2 == 'C' ||
            i1 == 'D' && i2 == 'F' ||
            i2 == 'A' && i1 == 'B' ||
            i2 == 'A' && i1 == 'C' ||
            i2 == 'B' && i1 == 'C' ||
            i2 == 'D' && i1 == 'F'
            )
            {
                cout<<"1";
                if(
                i1 == 'A' && i2 == 'B' ||
                i1 == 'B' && i2 == 'C' ||
                i1 == 'D' && i2 == 'F' ||
                i2 == 'A' && i1 == 'B' ||
                i2 == 'B' && i1 == 'C' ||
                i2 == 'D' && i1 == 'F'
                ) cout<<"1";
                else cout<<"0";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    cout<<"\n";
    return 0;
}