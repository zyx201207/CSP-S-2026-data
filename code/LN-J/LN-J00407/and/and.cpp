#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans=0,t[200005];
long long a[200005];
bool vis[200005]={};
void dfs(int m,int sb){
    if(sb==m){
        long long tmp=t[0];
        for(int i=1;i<m;i++){
            tmp=tmp&t[i];
        }
        ans=max(tmp,ans);
        return;
    }
    for(int i=0;i<n;i++){
        if(vis[i]==0){
            t[sb]=a[i];
            vis[i]=1;
            dfs(m,sb+1);
            vis[i]=0;
        }
    }
}
int main(){
    //fixed
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    dfs(m,0);
    cout<<ans;
}
