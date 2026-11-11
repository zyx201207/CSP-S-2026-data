#include<bits/stdc++.h>
using namespace std;
#define N 2000005
int c,t;
long long x[N];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--)
    {
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        if(d>=2*(x[2]-x[1])&&d<3*(x[2]-x[1]))cout<<n-2<<'\n';
        else cout<<0<<'\n';
    }
    return 0;
}