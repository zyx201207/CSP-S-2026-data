#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],sm[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) sm[i]=sm[i-1]+a[i];
    int ans=1;
    for(int i=1;i<=n;i++){
        int l=1,r=i;
        while(l<r){
            int mid=(l+r)>>1;
            if(a[i]*(i-mid+1)-(sm[i]-sm[mid-1])<=m) r=mid;
            else l=mid+1;
        }
        ans=max(ans,i-r+1);
    }
    printf("%lld",ans);
    return 0;
}