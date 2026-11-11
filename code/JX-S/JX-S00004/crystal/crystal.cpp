#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],c[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>a[i];
    sort(a+1,a+1+n);
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    for(int i=2; i<=n; i++)
    {
        b[i]=b[i]+a[i]-a[1];
    }
    for(int i=2; i<=n; i++)
    {
        c[i]=c[i-1]+b[i];
    }
    for(int i=2; i<=n; i++)
    {
        b[i]=b[i]*(i-1)-c[i-1];
    }
    for(int i=n; i>=1; i--)
    {
        if(m>=b[i])
        {
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}
