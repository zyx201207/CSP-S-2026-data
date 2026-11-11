#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
int testpoint,n,m,ddddd,query;
int w[500005],d[500005],bel[500005][21],pos[500005][21];
int k[505];
vector<int> t[505],p[505];
int mp[505][505],dist[505];
bool vis[505];
int endp[505];
priority_queue<pii,vector<pii>,greater<pii> > q;
map<pii,int> god;
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    memset(mp,0x3f3f3f3f,sizeof(mp));
    cin>>testpoint>>n>>m>>ddddd>>query;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        t[i].push_back(-1);
        p[i].push_back(-1);
        for(int j=1;j<=k[i];j++){
            int v,ti; cin>>v>>ti;
            t[i].push_back(ti);
            p[i].push_back(v);
            d[v]++;
            bel[v][d[v]]=i;
            pos[v][d[v]]=j;
            god[{i,v}]=ti;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=d[i];j++){
            for(int k=j+1;k<=d[i];k++){
                int u=bel[i][j],v=bel[i][k],costu=god[{u,i}],costv=god[{v,i}];
                int cal=costu+costv;
                mp[u][v]=mp[v][u]=min(mp[u][v],cal);
            }
        }
    }
    for(int i=1;i<=n;i++)mp[i][i]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)mp[i][j]=0;
        }
    }
    while(query--){
        int ans=LLONG_MAX;
        int s,ed; cin>>s>>ed;
        while(!q.empty())q.pop();
        memset(vis,0,sizeof(vis));
        memset(dist,0x3f3f3f3f,sizeof(dist));
        memset(endp,0,sizeof(endp));
        for(int i=1;i<=d[ed];i++){
            int line=bel[ed][i];
            endp[line]=i;
        }
        for(int i=1;i<=d[s];i++){
            int line=bel[s][i];
            int posi=pos[s][i];
            int val=w[s]+t[line][posi];
            q.push({val,line});
            dist[line]=val;
        }
        while(!q.empty()){

            int currentline=q.top().second;
            q.pop();
            if(endp[currentline]){
                int tmp=t[currentline][pos[ed][endp[currentline]]];
                ans=min(ans,dist[currentline]+w[ed]+tmp);
            }
            if(vis[currentline])continue;
            vis[currentline]=1;
            for(int v=1;v<=n;v++){
                if(mp[currentline][v]==0x3f3f3f3f)continue;
                if(dist[currentline]+mp[currentline][v]<=dist[v]){
                    dist[v]=dist[currentline]+mp[currentline][v];
                    q.push({dist[v],v});
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
