#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans;
int a[200010];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans=max(ans,a[i]);
    }
    cout<<ans;
    return 0;
}
