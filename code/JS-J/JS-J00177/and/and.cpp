#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
void dfs(int s,int l,int u){
    if(u==m){
        ans=s;
        return;
    }
    if(n-l+u<m){
        return;
    }
    for(int i=l+1;i<=n;i++){
        int ns=s&a[i];
        if(ns<=ans) continue;
        dfs(ns,i,u+1);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n-m+1;i++){
        dfs(a[i],i,1);
    }
    cout<<ans;
    return 0;
}
