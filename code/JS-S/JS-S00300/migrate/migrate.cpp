#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
unordered_map<int,int>mp,vis,dis;
int c,T,n,cnt,head[N*4];
long long a[N],d;
long long ans;
struct edge{
    int v,nxt;
}g[N*10];
void link(int u,int v){
    g[++cnt]={v,head[u]};
    head[u]=cnt;
}
void bfs(int s){
    queue<int>q;q.push(s);
    queue<int>p;p.push(0);
    dis[s]=0;
    while(!q.empty()){
        int u=q.front();q.pop();
        int st=p.front();p.pop();
        if(st<=dis[u]&&vis[u]){
            dis[u]=st;vis[u]--;
        }
        for(int i=head[u];i;i=g[i].nxt){
            int v=g[i].v;
            if(vis[v]&&st+1<=dis[v]){
                q.push(v);p.push(st+1);
            }
        }
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            int j=upper_bound(a+1,a+n+1,a[i]+d)-(a+1);
            for(int k=i+1;k<=j;k++)link(i,k);
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)vis[j]=3,dis[j]=INT_MAX;
            bfs(i);
            for(int j=i+1;j<=n;j++)ans+=(vis[j]==1);
        }
        cout<<ans<<'\n';
        for(int i=1;i<=cnt;i++)g[i]={0,0};
        for(int i=1;i<=n;i++)head[i]=0;
    }
    return 0;
}
