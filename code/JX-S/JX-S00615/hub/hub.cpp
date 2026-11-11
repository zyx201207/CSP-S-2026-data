#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<unordered_map>
using namespace std;
const int N=1e6+5;
int n,k,ans=1e9,v[N],d[N],t[N];
bool vis[N];
vector<int> e[N];
void bfs(int st){
    memset(d,-1,sizeof(d));
    d[st]=0;
    queue<int> q;
    q.push(st);
    while (!q.empty()){
        int u=q.front();
        q.pop();
        for (int v:e[u]){
            if (d[v]==-1){
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
}
void solve(){
    memset(t,0x3f,sizeof(t));
    unordered_map<int,bool> mp;
    for (int i=1;i<=k;i++){
        bfs(i);
        mp[v[i]]=1;
        for (int i=1;i<=n;i++){
            t[i]=min(t[i],d[i]);
        }
    }
    int sum=0;
    for (int i=1;i<=n;i++){
        if (!mp.count(i)){
            sum=max(sum,t[i]);
        }
    }
    ans=min(ans,sum);
}
void dfs(int depth,int idx){
    if (depth>k){
        solve();
        return ;
    }
    for (int i=idx+1;i<=n;i++){
        if (!vis[i]){
            v[depth]=i;
            vis[i]=1;
            dfs(depth+1,i);
            vis[i]=0;
        }
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    scanf("%d %d",&c,&t);
    while (t--){
        scanf("%d %d",&n,&k);
        for (int i=1;i<n;i++){
            int u,v;
            scanf("%d %d",&u,&v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        ans=1e9;
        dfs(1,0);
        printf("%d\n",ans);
    }
    return 0;
}
