#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=500005;
int a[maxn],sum[maxn];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];
    int ans=1;
    for(int i=1,j=1;i<=n;i++){
        while((j-i)*a[j]-(sum[j-1]-sum[i-1])<=m && j<=n)
            j++;
        ans=max(ans,j-i);
    }
    cout<<ans<<endl;
    return 0;
}
