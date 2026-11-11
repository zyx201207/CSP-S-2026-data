#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
const int N=5e5+2;
int n,ans;
ll m,mn;
ll a[N];
ull na[N],pre[N];
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    mn=1e18;
    for(int i=1;i<=n;i++) cin>>a[i],mn=min(mn,a[i]);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) {
        if(mn<0) na[i]=a[i]-mn;
        else    na[i]=a[i];
        pre[i]=pre[i-1]+na[i];
    }
    for(int i=1;i<=n;i++) {
        int l=1,r=i-1;
        int res=-1;
        while(l<=r) {
            int mid=(l+r)>>1;
            //cout<<mid<<" "<<(i-mid)<<" "<<(pre[i-1]-pre[mid-1])<<" "<<(i-mid)*na[i]-(pre[i-1]-pre[mid-1])<<"\n";
            if(m>=(i-mid)*na[i]-(pre[i-1]-pre[mid-1])) {
                res=mid;
                r=mid-1;
            } else    l=mid+1;
        }
        ans=max(ans,i-res+1);
    }
    cout<<ans<<"\n";
    return 0;
}