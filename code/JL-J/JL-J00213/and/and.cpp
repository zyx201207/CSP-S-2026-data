#include<bits/stdc++.h>
using namespace std;
int a[200005];
int vis[200005];
int b[200005];
int n,m;
int ans=0;
void dfs(int x){
    if(x==m+1){
        int t=b[1];
        for(int i=2;i<=m;i++){
            t=t&b[i];
        }
        ans=max(ans,t);
        return ;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==1) continue;
        vis[i]=1;
        b[x]=a[i];
        dfs(x+1);
        vis[i]=0;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1);
    cout<<ans;
}
