#include<bits/stdc++.h>
#define int long long
#define N 1000005
using namespace std;
int n,m,a[N],sum[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    int res=0;
    for(int i=1;i<=n;i++){
        int l=0,r=i;
        while(l<r){
            int mid=l+r>>1;
            if((i-mid+1)*a[i]-(sum[i]-sum[mid-1])<=m) r=mid;
            else l=mid+1;
        }
        res=max(res,i-l+1);
    }
    cout<<res;
}