#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500009],tp=0,ans=1;
bool v[500009];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }sort(a+1,a+n+1);
    for(int r=1,l=1;r<n;){
        while(tp+(r-l+1)*(a[r+1]-a[r])<=m&&r<n){
            tp+=(r-l+1)*(a[r+1]-a[r]);
            r++;
        }ans=max(ans,r-l+1);
        while(l<r&&tp+(r-l+1)*(a[r+1]-a[r])>m){
            tp-=(a[r]-a[l]);
            l++;
        }ans=max(ans,r-l+1);
    }printf("%lld",ans);
    return 0;
}
