#include<bits/stdc++.h>
using namespace std;
string a,b;
int A,B;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>A>>a;
    cin>>B>>b;
    if(A==B)
    {
        cout<<"1";
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    if(a[0]==b[0]&&a[1]==b[1])
    {
        cout<<1;
    }
    else
    {
        cout<<"000";
        return 0;
    }
    if(a[2]<='C')
    {
        if(b[2]<='C')
        {
            cout<<"1";
            if(a[2]=='B'||b[2]=='B')
            {
                cout<<"1";
                return 0;
            }
            else
            {
                cout<<"0";
                return 0;
            }
        }
        cout<<"00";
        return 0;
    }
    else
    {
        if(b[2]>='D')
        {
            cout<<"11";
            return 0;
        }
        cout<<"00";
    }
    return 0;
}
