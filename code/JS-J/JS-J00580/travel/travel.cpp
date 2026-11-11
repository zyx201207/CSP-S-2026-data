#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
char cw,cq;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>cw;
    cin>>c>>d>>cq;
    if(a!=c)
    {
        cout<<"0000\n";
        return 0;
    }
    if(b!=d)
    {
        cout<<"1000\n";
        return 0;
    }
    bool l=(cw<='C'&&cq>='D');
    bool r=(cq<='C'&&cw>='D');
    if(l||r)
    {
        cout<<"1100\n";
        return 0;
    }
    if(cw<='C')
    {
        if(abs(cw-cq)!=1)
        {
            cout<<"1110\n";
            return 0;
        }
    }
    else
    {
        if(abs(cw-cq)!=2)
        {
            cout<<"1110\n";
            return 0;
        }
    }
    cout<<"1111\n";

}
