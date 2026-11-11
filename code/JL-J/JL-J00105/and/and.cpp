#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 2000010
int n,m,a[N],ans=0,vis[N],cc;
void dfs(int dep,int cnt,int sum){
    //cout<<sum<<endl;
    if(dep==n+1){
        if(cnt==m){
            ans=max(ans,sum);
        }
        return ;
    }
    if(cnt==m){
        ans=max(ans,sum);
        return ;
    }
    if(sum==0){
        dfs(dep+1,cnt+1,a[dep]);
    }
    else{
        dfs(dep+1,cnt+1,sum&a[dep]);
    }
    dfs(dep+1,cnt,sum);
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,0,0);
    cout<<ans<<endl;
    return 0;
}
