#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans;
bool vis[200010];
void dfs(int x,int y){
    if(!x){
        ans=max(ans,y);
        return;
    }
    if(y<ans)return;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=true;
            if(x==m)dfs(x-1,a[i]);
            else dfs(x-1,y&a[i]);
            vis[i]=false;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    dfs(m,0);
    cout<<ans;
    return 0;
}
