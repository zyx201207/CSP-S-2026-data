#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int c[300005];
int ans[300005];
int vis[300005];
int n,m;
int dfs(int x){
    if(x==n+1){
        return 0;
    }
    if(vis[a[x]]==0){
        ans[a[x]]++;
    }
    vis[a[x]]=1;
    if(b[x]==-1){
        int p=dfs(x+1);
        vis[a[x]]=0;
        return 0;
    }
    else{
        int p=dfs(b[x]);
        vis[a[x]]=0;
        return 0;
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    if(m==n){
        for(int i=1;i<=n;i++){
            int o;
            cin>>o;
            ans[o]+=n-i+1;
        }
        for(int i=1;i<=m;i++){
            cout<<ans[i]<<" ";
        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        b[i]=-1;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(c[a[i]]!=0){
            b[c[a[i]]]=i;
        }
        c[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        int p=dfs(i);
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
