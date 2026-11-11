#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N],sum[N];
int n,m;
inline bool check(int i,int x){
    int val=(i-x+1)*a[i];
    int val2=sum[i]-sum[x-1];
    if (abs(val-val2)<=m) return 1;
    else return 0;
}
inline void solve(){
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    int mx=0;
    for (int i=1;i<=n;i++){
        int l=1,r=i,ans=0;
        while (l<=r){
            int mid=(l+r)>>1;
            if (check(i,mid)) ans=i-mid+1,r=mid-1;
            else l=mid+1;
        }
        mx=max(mx,ans);
    }
    cout<<mx;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int T=1;
    while (T--) solve();
    return 0;
}
