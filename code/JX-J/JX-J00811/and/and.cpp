#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a[200005],f[200005];
void dfs(int x,int y,int z){
    if(y==m){
        ans=max(ans,z);
        return;
    }
    if(x>n) return;
    if(n-x+1<=m-y) return;
    dfs(x+1,y,z);
    if(!f[x]) dfs(x+1,y+1,z&a[x]);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        f[i]=1;
        dfs(1,1,a[i]);
        f[i]=0;
    }
    cout<<ans;
    return 0;
}
