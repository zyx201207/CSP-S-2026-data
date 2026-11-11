#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans,n,m,a[200010];
void dfs(int dep,int cnt,int now){
    if(dep>n){
        if(cnt==m){
            ans=max(ans,now);
        }
        return;
    }
    if(cnt+1<=m){
        dfs(dep+1,cnt+1,(now&a[dep]));
    }
    else{
        dfs(dep+1,cnt,now);
    }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<ans;
    return 0;
}
