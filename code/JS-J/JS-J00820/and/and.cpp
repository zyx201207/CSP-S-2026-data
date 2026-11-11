#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans=0,a[200010];
void dfs(int dep,int nw,int pre){
    if(dep>m){
        ans=max(ans,nw);
        return;
    }
    for(int i=pre+1;i<=n-m+dep;i++)if((nw&a[i])>ans)dfs(dep+1,nw&a[i],i);
    return;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    dfs(1,0xffffffffffffffff,0);
    cout<<ans;
    return 0;
}
