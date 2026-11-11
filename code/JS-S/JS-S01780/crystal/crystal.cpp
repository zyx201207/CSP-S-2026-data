#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],pos=1,sum[500005],ans;
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
        while((1ll*i-pos+1)*a[i]-sum[i]+sum[pos-1]>m) pos++;
        ans=max(ans,i-pos+1);
    }
    cout<<ans;
    return 0;
}
