#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int rc,xc;
    string rz,xz;
    cin>>rc>>rz>>xc>>xz;
    if(rc!=xc)
    {
        cout<<"0000";
    }
    else if(rz[2]!=xz[2])
    {
        cout<<"1000";
    }
    else if(rz[3]<'C'&&rz[3]<'C')
    {
        if(rz[3]+1==xz[3]+0||rz[3]-1==xz[3]+0)
        {
            cout<<"1111";
        }
        else
        {
            cout<<"1110";
        }
    }
    else
    {
        cout<<"1111";
    }
    return 0;
}
