#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
namespace YuJH{
    int n;
    long long d;
    long long x[5010];
    int dis[5010],cnt[5010];
    void bfs(int s){
        memset(dis,0x3f,sizeof(dis));
        memset(cnt,0,sizeof(cnt));
        dis[s]=0;
        cnt[s]=1;
        for(int u=s;u<=n;u++){
            for(int v=u+1;v<=n;v++)
                if(x[v]-x[u]<=d){
                    if(dis[v]>dis[u]+1){
                        dis[v]=dis[u]+1;
                        cnt[v]=cnt[u];
                    }
                    else if(dis[v]==dis[u]+1){
                        cnt[v]+=cnt[u];
                        cnt[v]=min((int)1e9,cnt[v]);
                    }
                }
        }
        return;
    }
    int ans;
    int main(){
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>x[i];
        ans=0;
        for(int i=1;i<=n;i++){
            bfs(i);
            for(int j=i+1;j<=n;j++)
                if(cnt[j]==2)
                    ans++;
        }
        cout<<ans;
        return 0;
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int C,T;
    cin>>C>>T;
    while(T--){
        YuJH::main();
        cout<<'\n';
    }
    return 0;
}