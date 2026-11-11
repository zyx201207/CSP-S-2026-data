#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],q[500005];
bool check(int d){
    for(int i=d;i<=n;i++)
        if(d*a[i]-q[i]+q[i-d]<=m) return 1;
    return 0;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) q[i]=q[i-1]+a[i];
    int l=1,r=n,ans;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)){
            l=mid+1;
            ans=mid;
        }else r=mid-1;
    }
    cout<<ans;
    return 0;
}
