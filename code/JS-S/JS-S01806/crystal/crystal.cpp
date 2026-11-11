#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
int n,m;
int a[N];
int sum[N];
int ask(int l,int r){
    return sum[r]-sum[l-1];
}
bool check(int mid){
    int ans=LLONG_MAX;
    for(int l=1;l<=n-mid+1;l++){
        int r=l+mid-1;
        ans=min(ans,a[r]*(r-l+1)-ask(l,r));
    }
    // if(mid==5000) cout<<ans<<'\n';
    return ans<=m;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    int l=1,r=n+1;
    while(l+1<r){
        int mid=l+r>>1;
        if(check(mid)) l=mid;
        else r=mid;
    }
    cout<<l<<'\n';
    return 0;
}