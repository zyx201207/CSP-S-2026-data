#include <bits/stdc++.h>
using namespace std;

int quickpow(int a,int b,int q)
{
    int res=1;
    while (b!=0)
    {
        if (b%2==1) res=res*a%p;
        a=a*a%p;
        b/=2;
    }
    return res;
}




int main()
{
     freopen("hub.in","r",stdin);
     freopen("hub.out","w",stdout);
     ios::sync_with_stdio(0);
     cin.tie(0);cout.tie(0);

     return 0;
}
