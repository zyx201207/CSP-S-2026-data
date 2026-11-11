#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
namespace YuJH{
    int n,m;
    vector<int> T[4010];
    int fa[4010];
    int dep[4010];
    void dfs(int u,int f){
        fa[u]=f;
        dep[u]=dep[f]+1;
        for(int v:T[u])
            if(v!=f)
                dfs(v,u);
        return;
    }
    int p[4010];
    bool flag[4010];
    int cnt[4010];
    void dfs(int u){
        for(int v:T[u])
            if(v!=fa[u]){
                dfs(v);
                flag[u]|=flag[v];
                cnt[u]+=cnt[v];
            }
        if(flag[u])
            cnt[u]++;
        return;
    }
    int f[4010][4010];
    int d[4010];
    int maxx;
    int ans=1e9;
    void bfs(int a){
        memset(d,0x3f,sizeof(d));
        d[a]=0;
        queue<int> q;
        q.push(a);
        maxx=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int v:T[u])
                if(fa[v]!=a)
                    if(d[v]==0x3f3f3f3f){
                        d[v]=d[u]+1;
                        q.push(v);
                        maxx=max(maxx,d[v]);
                        if(maxx>ans)
                            return;
                    }
        }
        return;
    }
    void bfs(int a,int b){
        memset(d,0x3f,sizeof(d));
        d[a]=d[b]=0;
        queue<int> q;
        q.push(a);
        q.push(b);
        maxx=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int v:T[u])
                if(fa[v]!=a&&fa[v]!=b)
                    if(d[v]==0x3f3f3f3f){
                        d[v]=d[u]+1;
                        q.push(v);
                        maxx=max(maxx,d[v]);
                        if(maxx>ans)
                            return;
                    }
        }
        return;
    }
    int main(){
        cin>>n>>m;
        for(int i=1,u,v;i<n;i++){
            cin>>u>>v;
            T[u].push_back(v);
            T[v].push_back(u);
        }
        if(m==2){
            int ans=1e9;
            for(int i=1;i<=n;i++)
                for(int j=i+1;j<=n;j++){
                    bfs(i,j);
                    ans=min(maxx,ans);
                }
            cout<<ans;
            return 0;
        }
        dfs(1,0);
        for(int i=1;i<=n;i++)
            p[i]=i;
        for(int k=0;k<=n;k++){
            if(k)
                for(int i=1;i<=n;i++)
                    p[i]=fa[p[i]];
            memset(flag,0,sizeof(flag));
            memset(cnt,0,sizeof(cnt));
            for(int i=1;i<=n;i++)
                if(p[i])
                    flag[p[i]]=1;
            dfs(1);
            for(int i=1;i<=n;i++)
                f[i][k]=cnt[i];
        }
        for(int i=1;i<=n;i++){
            bfs(i);
            for(int k=maxx;k<=ans&&k<=n;k++)
                if(f[i][k]<=m){
                    ans=k;
                    break;
                }
        }
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++){
                bfs(i,j);
                for(int k=maxx;k<=ans&&k<=n;k++)
                    if(f[i][k]+f[j][k]<=m){
                        ans=k;
                        break;
                    }
            }
        cout<<ans;
        return 0;
    }
    void clear(){
        for(int i=0;i<=4005;i++)
            T[i].clear();
        memset(fa,0,sizeof(fa));
        memset(dep,0,sizeof(dep));
        memset(p,0,sizeof(p));
        memset(flag,0,sizeof(flag));
        memset(cnt,0,sizeof(cnt));
        memset(f,0,sizeof(f));
        memset(d,0,sizeof(d));
        ans=1e9;
        return;
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int C,T;
    cin>>C>>T;
    while(T--){
        YuJH::main();
        YuJH::clear();
        cout<<'\n';
    }
    return 0;
}