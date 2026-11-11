#include<bits/stdc++.h>
#include<bits/extc++.h>
#define endl '\n'
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
const int MAXN=1e6;
int c,n,k;
vector<int>g[MAXN+11],p;
bitset<1111>f[1111];
int fa[MAXN+11];
int find(int x){
    if(fa[x]!=x)
        fa[x]=find(fa[x]);
    return fa[x];
}
void merge(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx!=fy)
        return;
    fa[fx]=fy;
    return;
}
int minn;
void dfs(int lst=0){
    if(p.size()==k){
        for(int i=1;i<=n;i++)
            fa[i]=i;
        for(int i=0;i<k;i++)
            for(int j=i+1;j<k;j++)
                if(f[p[i]][p[j]])
                    merge(p[i],p[j]);
        unordered_set<int>s;
        for(int i=0;i<k;i++)
            s.insert(find(p[i]));
        if(s.size()<=2){
            queue<int>q;
            vector<int>dist(n+1,-1);
            for(int i=0;i<k;i++)
                q.push(p[i]),dist[p[i]]=0;
            int maxx=0;
            while(!q.empty()){
                int u=q.front();
                q.pop();
                for(int v:g[u])
                    if(!~dist[v])
                        q.push(v),maxx=max(maxx,dist[v]=dist[u]+1);
            }
            minn=min(minn,maxx);
        }
        return;
    }
    for(int i=lst+1;i<=n;i++){
        p.emplace_back(i);
        dfs(i);
        p.pop_back();
    }
    return;
}
void main_init(){
    cin>>c;
    return;
}
void solve(){
    for(int i=1;i<=n;i++)
        g[i].clear(),f[i]=bitset<1111>();
    cin>>n>>k;
    if(k==n-1)
        return cout<<0<<endl,void();
    else if(k==n-2)
        return cout<<1<<endl,void();
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        f[u][v]=f[v][u]=true;
    }
    minn=n;
    dfs();
    cout<<minn<<endl;
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    main_init();
    int T=1;
    cin>>T;
    while(T--)
        solve();
    return 0;
}