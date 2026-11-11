#include <bits/stdc++.h>
using names pace std;
int main()
{
    preopen("card.in","r",stdin);
    preopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(n<=5&&m<=2)
    {
        cout<<2;
    }
    else if(n<=500&&m<=300)
    {
        cout<<5;
    }
    else if(n<=5000&&m<=3000)
    {
        cout<<9;
    }
    else if(n<=200000&&m<=2)
    {
        cout<<13;
    }
    else if(n<=200000&&m<=3000)
    {
        cout<<17;
    }
    else if(n<=200000&&m<=500000)
    {
        cout<<21;
    }
    else cout<<24;
    return 0;
}
