#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500003],s[500003],n,m;
bool check(int x){
    for(int i=1;i+x-1<=n;i++){
        int j=i+x-1;
        if(a[j]*x-(s[j]-s[i-1])<=m ){
            return 1;
        }
    }
    return 0;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i],s[i]=s[i-1]+a[i];
    sort(a+1,a+n+1);
    int ans=0,l=1,r=n;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)) ans=mid,l=mid+1;
        else r=mid-1;
    }
    cout<<ans<<'\n';
}
