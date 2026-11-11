#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 5e5+114;
int a[maxn];
int pre[maxn],n,m;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int ans=0;
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
    for(int i=1;i<=n;i++){
        int l=0,r=i;
        while(l+1<r){
            int mid=(l+r)>>1;
            if((i-mid+1)*a[i]-(pre[i]-pre[mid-1])<=m) r=mid;
            else l=mid;
        }
        ans=max(ans,i-r+1);
    }
    cout<<ans<<"\n";
    return 0;
}