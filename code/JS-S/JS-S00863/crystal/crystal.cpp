#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
const int N=5e5+5;
ll n,m;
ll a[N];
ll pre[N];
ll ans;
bool check(int i,int mid){
    ll sum=1LL*a[i]*mid-pre[i-1]+pre[i-mid-1];
    return sum<=m;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
    for(int i=1;i<=n;i++){
        int l=0,r=i-1,cnt=0;
        while(l<=r){
            int mid=(l+r)>>1;
            if(check(i,mid)) cnt=l=mid+1;
            else r=mid-1;
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}
