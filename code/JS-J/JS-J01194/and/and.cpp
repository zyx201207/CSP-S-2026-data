#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN (int)(2e5+10)
int n,m,ans=0,a[MAXN],vis[MAXN]={0};
void dfs(int res,int idx,int sum){
    if(res==0) {ans=max(ans,sum); return;}
    if(sum<=ans) return;
    for(int i=idx+1;i<=n-res+1;i++){
        dfs(res-1,i,(sum&a[i]));
    } return;
}
int comp(int p,int q){return p>q;}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1,comp);
    for(int i=1;i<=n-m+1;i++){
        dfs(m-1,i,a[i]);
    }cout<<ans<<"\n";
    return 0;
}