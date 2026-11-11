#include <bits/stdc++.h>
using namespace std;
string r2,x2;
int r1,x1;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>r1>>r2>>x1>>x2;
    if(r1==x1)
    {
        cout<<1;
        bool f=1;
        for(int i=0;i<2;i++)
        {
            if(x2[i]!=r2[i]) f=0;
        }
        if(f)
        {
            cout<<1;
            int pd1=0,pd2=0;
            if(x2[2]>='A'&&x2[2]<='C') pd1=1;
            if(r2[2]>='A'&&r2[2]<='C') pd2=1;
            if(pd1==pd2)
            {
                cout<<1;
                if(max(x2[2],r2[2])-1==min(x2[2],r2[2])) cout<<1;
                else cout<<0;
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
    }
    else
    {
        cout<<"0000";
        return 0;
    }





    return 0;
}
