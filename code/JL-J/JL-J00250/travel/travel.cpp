#include<bist/stdc++.h>
using namespace std;
int main()
{
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        bool v=true;
        cout<<1;
    }
    else
    {
        bool v=0;
        cout<<0;
    }
    if(cpp.s1(2)==cpp.s2(2))
    {
        bool u=true;
        cout<<1;
    }
    else
    {
        bool u=0;
        cout<<0;
    }
    if(v==u&&u==1)
    {
        cout<<1<<1;
    }
    else if(v==1&&u==0)
    {
        cout<<1<<0;
    }
    else
    {
        cout<<0<<0;
    }
    return 0;
}
