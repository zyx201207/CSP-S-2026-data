#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;
ll a[N],sum[N];
int n;
ll m;
int fnd(int x){
    int l=1,r=x,ret=-1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(a[x]*(x-mid+1)-sum[x]+sum[mid-1]<=m){
            ret=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    return ret;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,i-fnd(i)+1);
    }
    cout<<ans<<'\n';
    return 0;
}
