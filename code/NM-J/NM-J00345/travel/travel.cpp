#include <iostream>
using namespace std;
int mian()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2,s1,s2;
    cin>>c1>>c2>>s1>>s2;
    if(c1==c2)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }


    if(s1%100 && s1%1000 ==s2%100 &&s2%1000)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }


    if(s1%10=="A" || s1%10=="B" || s1%10=="C" && s2%10=="A" || s2%10=="B" || s2%10=="C" )
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }


    if(s1%10=="D" || s1%10=="F" && s2%10=="D" || s2%10=="F")
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }


    if(s1%10=="A" && s2%10=="B" || s1%10=="B" && s2%10=="A" || s1%10=="B" && s2%10=="C" || s1%10=="C" && s2%10=="B"|| s1%10=="D" && s2%10=="F" || s1%10=="F" && s2%10=="D")
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    return 0;
}
