#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll a[500050],b[500050],c[500050],d[500050];
ll ans=0;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    a[0]=0;b[0]=0;c[0]=0;d[0]=0;
    sort(a+1,a+n+1);
    a[0]=0;b[0]=0;c[0]=0;d[0]=0;
    int ans=0;
    d[n+1] = LONG_LONG_MAX;
    for (int j=1;j<=n;j++){
        c[j-1]=0;
        for (int i=j;i<=n;i++){
            b[i] = a[i]-a[j];
            c[i] = c[i-1]+b[i];
            d[i] = (i-j+1)*b[i] - c[i];
        }
        int tem = upper_bound(d+j,d+n+1,m)-(d+j);
        ans = max(ans,tem);
    }
    cout << ans;
    return 0;
}
