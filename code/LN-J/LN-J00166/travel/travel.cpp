#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r","std.in");
    freopen("travel.out","w","std.out");
    string a,aa,b,bb;
    cin>>a>>aa>>b>>bb;
    if(a==b)
    {
        cout<<1;
    }
    else
    {
        cout<<"0000";
        return 0;
    }


    if(aa[0]==bb[0]&&aa[1]==bb[1])
    {
        cout<<1;
        if(aa[2]<='C'&&bb[2]<='C')
        {
            cout<<1;
            if(aa[2]=='B'||bb[2]=='B')
            {
                cout<<1;
                return 0;
            }
            else
            {
                cout<<0;
                return 0;
            }
        }
        else if(aa[2]>'C'&&bb[2]>'C')
        {
            cout<<"11";
            return 0;
        }
        else
        {
            cout<<"00";
            return 0;
        }
    }
    else
    {
        cout<<"000";
        return 0;
    }
    return 0;
}
