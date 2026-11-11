#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+10;
int n,m,a[N],sum[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    int ans=0;
    for(int i=1,j=1;i<=n;i++){
        while((i-j)*a[i]-(sum[i-1]-sum[j-1])>m) j++;
        ans=max(ans,i-j+1);
    }
    cout<<ans;
    return 0;
}
