#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,ans;
int a[N],sum[N];
bool chk(int l,int r){
    int he=sum[r]-sum[l-1];
    int need=a[r]*(r-l+1)-he;
    if(need<=m) return true;
    return false;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++){
        int l=1,r=i,mid,res=0;
        while(l<=r){
            mid=(l+r)>>1;
            if(chk(mid,i)) res=mid,r=mid-1;
            else l=mid+1;
        }
        ans=max(ans,i-res+1);
    }
    cout<<ans<<'\n';
    return 0;
}
