#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,s1,c2,s2;
    cin >>c1>>s1>>c2>>s2;
    if(c1 = c2)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    for(int i=1;1<=i<=18;i++)
    {
        if(s1=s2=i)
        {
            cout<<1;
        }
        else
        {
            cout<<0;
        }
    }
    for(int j;j=4;j++)
    {
       if(s1=s2=j)
       {
           cout<<0;
       }
       else
       {
           cout<<1;
       }
    }
    for(int r;r=3;r++)
    {
        if(s1=s2=r)
        {
            cout<<0;
        }
        else
        {
            cout<<1;
        }
        if(s1=s2=r+2)
        {
            cout<<1;
        }
    }
    return 0;
}






























































