#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int n,m;
int a[maxn];
int sum[maxn];
int ans=0;
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    int idx=0;
    for(int i=1;i<=n;i++){
        while(idx<i&&a[i]*(i-idx)-(sum[i]-sum[idx])>m) idx++;
        ans=max(ans,i-idx);
    }
    cout<<ans;
    return 0;
}