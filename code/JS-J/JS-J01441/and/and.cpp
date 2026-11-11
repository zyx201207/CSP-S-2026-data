#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N];
bool vis[N];
int ans=-1e9;
void dfs(int x,int sum){
    if(x==m+1){
        ans=max(ans,sum);
        return ;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==true) continue;
        vis[i]=true;
        dfs(x+1,sum&a[i]);
        vis[i]=false;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    dfs(1,(1<<31)-1);
    cout<<ans<<"\n";
    return 0;
}
