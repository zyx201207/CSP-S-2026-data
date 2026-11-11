#include <bits/stdc++.h>
using namespace std;
int n,a[200005],b[200005];
long long m,ans,x[200005],y[200005];
char c[200005],d[200005];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i] >> c[i];
        b[i]=a[i],d[i]=c[i];
        m+=a[i];
    }
    reverse(b+1,b+n+1);
    reverse(d+1,d+n+1);
    for(int i=1;i<=n;i++) x[i]=x[i-1]+a[i],y[i]=y[i-1]+b[i];
    for(int i=1,j=1;i<=n;i++)
    {
        j=max(j-10,1);
        while(y[j]<=x[i])
        {
            ans+=max(0ll,min(x[i],y[j])-max(x[i]-a[i],y[j]-b[j]))*(c[i]!=d[j]);
            j++;
        }
        ans+=max(0ll,min(x[i],y[j])-max(x[i]-a[i],y[j]-b[j]))*(c[i]!=d[j]);
    }
    cout << ans/2;
}
