#include<bits/stdc++.h>
using namespace std;
const int N=1005;
#define int long long
int n,m,rt;
int a[N],dis[N][N],vis[N][N];
void dfs(int u){
    for(int i=u+1;i<=n;i++){
        if(a[i]-a[u]>m)break;
        if(dis[rt][i]>dis[rt][u]+1){
            dis[rt][i]=dis[rt][u]+1;
            vis[rt][i]=1;
            dfs(i);
        }else if(dis[rt][i]==dis[rt][u]+1){
            vis[rt][i]++;
            dfs(i);
        }else dfs(i);
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++){
            dis[i][i]=0;
            for(int j=i+1;j<=n;j++)dis[i][j]=INT_MAX,vis[i][j]=0;
        }
        for(int i=1;i<=n;i++)rt=i,dfs(i);
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++)if(vis[i][j]==2)ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}