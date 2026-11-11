/*
#include <bits/stdc++.h>
using namespace std;
const int inf=1<<30;
int n,k,dist[1000005],mx[1000005],son[1000005],lf[1000005][2],lg[1000005][2];
long long s[1000005];
vector<int> edges[1000005],edges2[1000005],f[1000005][2],g[1000005][2];
inline void dfs_e(int x,int last){
    mx[x]=dist[x];
    son[x]=0;
    for(auto y:edges2[x]){
        if(y!=last){
            dist[y]=dist[x]+1;
            dfs_e(y,x);
            mx[x]=max(mx[x],mx[y]);
            if(!son[x]||mx[y]>mx[son[x]]){
                son[x]=y;
            }
        }
    }
    if(son[x]){
        edges[x].push_back(son[x]);
        for(auto y:edges2[x]){
            if(y!=last&&y!=son[x]){
                edges[x].push_back(y);
            }
        }
    }
}
inline void dfs(int x,int d){
    if(!son[x]){
        f[x][0].push_back(1);
        g[x][0].push_back(0);
    }
    int sz=edges[x].size();
    for(auto y:edges[x]){
        dfs(y,d);
    }
    int f0=1,f1=inf;
    for(auto y:edges[x]){
        if(mx[y]-dist[x]>d){
            if(lf[y][0]<f[y][0].size()&&f[y][0].back()<inf){
                f0+=f[y][0].back();
            } else{
                f0=inf;
                break;
            }
        }
    }
    for(int i=1;i<=sz;i++){
        int y=edges[x][i-1];
        if(lf[y][0]<f[y][0].size()&&f[y][0].back()<inf){
            s[i]=s[i-1]+f[y][0].back();
        } else{
            s[i]=s[i-1]+inf;
        }
    }
    for(int i=1;i<=sz;i++){
        int y=edges[x][i-1];
        if(s[i-1]+s[sz]-s[i]<inf){
            f1=min(f1,(int)(s[i-1]+s[sz]-s[i])+min((lg[y][0]<g[y][0].size()? f[y][0][g[y][0][lg[y][0]]]:inf),(lf[y][1]<f[y][1].size()&&f[y][1].back()<inf? f[y][1].back():inf)));
        }
    }
    swap(f[x][0],f[son[x]][0]);
    swap(f[x][1],f[son[x]][1]);
    swap(lf[x][0],lf[son[x]][0]);
    swap(lf[x][1],lf[son[x]][1]);
    swap(g[x][0],g[son[x]][0]);
    swap(g[x][1],g[son[x]][1]);
    swap(lg[x][0],lg[son[x]][0]);
    swap(lg[x][1],lg[son[x]][1]);
    f[x][0].push_back(f0);
    f[x][1].push_back(f1);
    if(f[x][0].back()<inf){
        while(lg[x][0]<g[x][0].size()&&f[x][0][g[x][0].back()]>=f[x][0].back()) g[x][0].pop_back();
        g[x][0].push_back(f[x][0].size()-1);
    }
    if(f[x][1].back()<inf){
        while(lg[x][1]<g[x][1].size()&&f[x][1][g[x][1].back()]>=f[x][1].back()) g[x][1].pop_back();
        g[x][1].push_back(f[x][1].size()-1);
    }
    int mx0=0,mx1=0;
    //f[y][0][f[y][0].size()-i-1]
    if(d-(mx[son[x]]-dist[x])>0){
        for(auto y:edges[x]){
            if(y!=son[x]){
                for(int i=0;i<=min((int)f[y][0].size()-lf[y][0]-1,d-(mx[son[x]]-dist[x])-1);i++){
                    f[x][0][f[x][0].size()-(i+1)-1]=min(f[x][0][f[x][0].size()-(i+1)-1],f[y][0][f[y][0].size()-i-1]);
                    mx0=max(mx0,i+1);
                }
                for(int i=0;i<=min((int)f[y][1].size()-lf[y][1]-1,d-(mx[son[x]]-dist[x])-1);i++){
                    f[x][1][f[x][1].size()-(i+1)-1]=min(f[x][1][f[x][1].size()-(i+1)-1],f[y][1][f[y][1].size()-i-1]);
                    mx1=max(mx1,i+1);
                }
            }
        }
    }
}
inline bool check(int d){
    for(int i=1;i<=n;i++){
        f[i][0].clear();
        g[i][0].clear();
        lf[i][0]=lg[i][0]=0;
    }
    dfs(1,d);
    return min(f[1][0][g[1][0][lg[1][0]]],f[1][1][g[1][1][lg[1][1]]])<=k;
}
inline void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        edges[i].clear();
        edges2[i].clear();
    }
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        edges2[u].push_back(v);
        edges2[v].push_back(u);
    }
    dist[1]=0;
    dfs_e(1,-1);
    int L=-1,R=n+1;
    while(L+1<R){
        int M=L+R>>1;
        if(!check(L)){
            L=M;
        } else{
            R=M;
        }
    }
    cout<<R<<'\n';
}
int main(){
    //freopen("hub.in","r",stdin);
    //freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,T;
    cin>>c>>T;
    while(T--){
        solve();
    }

    return 0;
}
败局已定
T_T
*/
#include <bits/stdc++.h>
using namespace std;
int n,k,fa[15],dist[15];
vector<pair<int,int>> e;
vector<int> edges[15];
inline int findfa(int x){
    if(fa[x]==x) return x;
    return fa[x]=findfa(fa[x]);
}
inline void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) edges[i].clear();
    e.clear();
    for(int i=1,x,y;i<n;i++){
        cin>>x>>y;
        e.push_back({x,y});
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    int ans=1<<30;
    for(int i=1;i<1<<n;i++){
        if(__builtin_popcount(i)>k) continue;
        for(int j=1;j<=n;j++){
            if(i>>j-1&1){
                fa[j]=j;
            }
        }
        for(auto [x,y]:e){
            if((i>>x-1&1)&&(i>>y-1&1)){
                x=findfa(x),y=findfa(y);
                if(x!=y) fa[x]=y;
            }
        }
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(i>>j-1&1){
                if(findfa(j)==j) cnt++;
            }
        }
        if(cnt>2) continue;
        for(int j=1;j<=n;j++){
            dist[j]=-1;
        }
        queue<int> q;
        for(int j=1;j<=n;j++){
            if(i>>j-1&1){
                dist[j]=0;
                q.push(j);
            }
        }
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(auto y:edges[x]){
                if(dist[y]==-1){
                    dist[y]=dist[x]+1;
                    q.push(y);
                }
            }
        }
        int mx=0;
        for(int j=1;j<=n;j++){
            mx=max(mx,dist[j]);
        }
        ans=min(ans,mx);
    }
    cout<<ans<<'\n';
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,T;
    cin>>c>>T;
    while(T--){
        solve();
    }

    return 0;
}
