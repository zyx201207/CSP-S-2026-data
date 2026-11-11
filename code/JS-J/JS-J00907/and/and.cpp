#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,mmax;
int a[N];
bool vis[N];
void dfs(int x,int layer,int ans_now){
    ans_now=ans_now&a[x];
    if(ans_now<=mmax) return ;
    if(layer==0){
        mmax=max(mmax,ans_now);
        return ;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==false){
            vis[i]=true;
            dfs(i,layer-1,ans_now);
            vis[i]=false;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        memset(vis,false,sizeof(vis));
        vis[i]=true;
        dfs(i,m-1,a[i]);
        vis[i]=false;
    }
    cout<<mmax;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
