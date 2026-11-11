#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,l;
int a[500005],p[500005];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];

    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        p[i+1]=p[i]+a[i];
    }
    for(int r=1;r<=n;r++){
        while((r-l+1)*a[r]-(p[r+1]-p[l])>m){
            l++;
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans;

    return 0;
}
