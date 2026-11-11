#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    freopen("mirgrate.in","r",stdin);
    freopen("mirgrate.out","w",stdout);
    int c,t;cin>>c>>t;
    int a[t+1];
    for(int i=1;i<=t;i++)
    {
        int n,d;cin>>n>>d;
        int x[n+1];
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        if(x[n-1]<0)x[n-1]-=2*x[n-1];
        a[i]=x[n-1]/2;
    }
    for(int i=1;i<=t;i++)cout<<a[i]<<endl;
    return 0;
}
