#include<bits/stdc++.h>
#define int long long
#define N 500010
using namespace std;
inline int read(){
    int x=0;char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9') x=x*10+(c-'0'),c=getchar();
    return x;
}
struct STAND{
    int rd;
    int ts;
};
int c,n,m,d,q;
int w[N];
int val[510][510];
int ms[510][510];
int cnt[N];
vector <STAND> stand[N];
vector <pair<int,int>> road[510];
void djs(int st){
    int dis[510];
    int vis[510];
    for(int i=1;i<=n;i++){
        if(i==st) dis[i]=0,vis[i]=1;
        if(i!=st) dis[i]=INT_MAX,vis[i]=0;
    }
    priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> sq;
    sq.push({0,st});
    while(!sq.empty()){
        pair <int,int> p=sq.top();
        sq.pop();
        int x=p.second;
        int sto,minv=INT_MAX;
        for(int i=0;i<road[x].size();i++){
            int to=road[x][i].second;
            int v=road[x][i].first;
            if(vis[to]==0){
                if(v<minv) minv=v,sto=to;
                dis[to]=min(dis[x]+v,dis[to]);
                sq.push({dis[to],to});
            }
        }
        if(minv!=INT_MAX) vis[sto]=1;
    }
    for(int i=1;i<=n;i++) if(i!=st) ms[i][st]=ms[st][i]=dis[i];
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    c=read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;i++) w[i]=read();
    for(int i=1;i<=n;i++){
        int k;
        k=read();
        for(int j=1;j<=k;j++){
            int a,t;
            a=read(),t=read();
            cnt[a]++;
            stand[a].push_back({i,t});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j) val[i][j]=INT_MAX;
        }
    }
    for(int p=1;p<=m;p++){
        for(int i=0;i<cnt[p];i++){
            for(int j=i+1;j<cnt[p];j++){
                int x=stand[p][i].rd;
                int y=stand[p][j].rd;
                int t=min(stand[p][i].ts+stand[p][j].ts,val[x][y]);
                val[x][y]=t,val[y][x]=t;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j&&val[i][j]!=INT_MAX){
                road[i].push_back({val[i][j],j});
                road[j].push_back({val[i][j],i});
            }
        }
    }
    for(int st=1;st<=n;st++) djs(st);
    while(q--){
        int x,y;
        x=read(),y=read();
        int ans=INT_MAX;
        for(int i=0;i<cnt[x];i++){
            for(int j=0;j<cnt[y];j++){
                ans=min(ans,stand[x][i].ts+stand[y][j].ts+ms[stand[x][i].rd][stand[y][j].rd]);
            }
        }
        cout<<ans+w[x]+w[y]<<"\n";
    }
    return 0;
}
