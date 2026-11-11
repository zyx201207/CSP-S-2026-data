#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,ans=1;
int a[N],sum[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    int l=1;
    for(int i=2;i<=n;i++){
        while(sum[i]-sum[l-1]+m<(i-l+1)*a[i]&&l<=i) l++;
        ans=max(ans,i-l+1);
    }
    cout<<ans<<"\n";
    return 0;
}