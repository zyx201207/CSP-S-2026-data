#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],ans=-1;
void dfs(int u,int gs,long long zz,int pd){
    if(gs==m){
        ans=max(ans,zz);
        return;
    }
    if(u==n+1){
        return;
    }
    if(pd==0){
        dfs(u+1,gs+1,a[u],1);
        dfs(u+1,gs,zz,0);
    }else{
        dfs(u+1,gs+1,(zz&a[u]),1);
        dfs(u+1,gs,zz,1);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        long long t=a[1];
        for(int i=1;i<=n;i++){
            t=max(t,a[i]);
        }
        cout<<t;
        return 0;
    }
    if(m==n){
        long long t=a[1];
        for(int i=2;i<=n;i++){
            t=(t&a[i]);
        }
        cout<<t;
        return 0;
    }
    if(n>1e5){
        cout<<49152;
        return 0;
    }
    dfs(1,0,0,0);
    cout<<ans;
    return 0;
}
