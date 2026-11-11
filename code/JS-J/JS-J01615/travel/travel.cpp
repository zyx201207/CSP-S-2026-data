#include <bits/stdc++.h>
using namespace std;
main()
{
    freopen("trevel.in","r",stdin);
    freopen("trevel.out","w",stdout);
    string c1,s1,c2,s2,t,u;
    int a=0,b=0,c=0,d=0;
    cin>>c1>>s1>>c2>>s2;
    t=s1[2];
    u=s2[2];
    if(c1==c2)
    {
    a=1;
    }

    for(int i=0;i<=1;i++)
    {
        if(c1==c2&&s1[i]==s2[i])
            b=1;
    }
    if(t=="A"&&u=="B")
    d=1;
    c=1;
    if(t=="B"&&u=="A")
    d=1;
    c=1;
    if(t=="C"&&u=="D")
    d=1;
    c=1;
    if(t=="D"&&u=="C")
    d=1;
    c=1;
    if(t=="D"&&u=="E")
    d=1;
    c=1;
    if(t=="E"&&u=="D")
    d=1;
    c=1;
    if(t=="C"&&u=="E")
    c=1;
    if(t=="F"&&u=="C")
    c=1;
    cout<<a*1000+b*100+c*10+d;


    return 0;
}
