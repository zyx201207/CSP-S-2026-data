#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=510,maxm=5e5+10;
const ll inf=1e15;
int c,n,m,d,q,cnt,w[maxm],k[maxn];
int _w[maxn][maxm],_dis[maxn][maxn];
vector<int>a[maxn],t[maxn];
struct edge{
    int v,w;
};
vector<edge>mp[maxm*2];
ll dis[maxm*2];
bool vis[maxm];
struct node{
    int x;
    ll dis;
    friend bool operator<(const node &a,const node &b){
        return a.dis>b.dis;
    }
};
void dij(int s){
    for(int i=1;i<=m+n;i++){
        dis[i]=inf;
        vis[i]=false;
    }
    dis[s]=0;
    priority_queue<node>q;
    q.push({s,0});
    while(!q.empty()){
        int x=q.top().x;
        q.pop();
        if(vis[x]) continue;
        vis[x]=true;
        for(edge e:mp[x]){
            int v=e.v,w=e.w;
            if(dis[v]>dis[x]+w){
                dis[v]=dis[x]+w;
                q.push({v,dis[v]});
            }
        }
    }
}
void calc(int s){
    for(int i=1;i<=m+n;i++){
        dis[i]=inf;
        vis[i]=false;
    }
    dis[s]=0;
    vis[s]=true;
    deque<int>q;
    q.push_back(s);
    while(!q.empty()){
        int x=q.front();
        q.pop_front();
        for(edge e:mp[x]){
            int v=e.v,w=e.w;
            if(vis[v]) continue;
            vis[v]=true;
            dis[v]=min(dis[v],dis[x]+w);
            if(w==0){
                q.push_front(v);
            }
            else{
                q.push_back(v);
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&k[i]);
        a[i].resize(k[i]+10);
        t[i].resize(k[i]+10);
        for(int j=1;j<=k[i];j++){
            scanf("%d%d",&a[i][j],&t[i][j]);
            _w[i][a[i][j]]=t[i][j];
        }
    }
    if(c>=12&&c<=19){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k[i];j++){
                mp[a[i][j]].push_back({m+i,t[i][j]});
                mp[m+i].push_back({a[i][j],t[i][j]});
            }
        }
        while(q--){
            int s,t;
            scanf("%d%d",&s,&t);
            calc(s);
            printf("%lld\n",dis[t]+w[s]+w[t]);
        }
    }
    else if(c>=9&&c<=11){
        memset(_dis,-1,sizeof(_dis));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k[i];j++){
                for(int _k=1;_k<=n;_k++){
                    if(_k==i) continue;
                    if(_w[_k][a[i][j]]==0) continue;
                    if(_dis[i][_k]==-1) _dis[i][_k]=t[i][j]+_w[_k][a[i][j]];
                    else  _dis[i][_k]=min(_dis[i][_k],t[i][j]+_w[_k][a[i][j]]);
                }
            }
        }
        while(q--){
            int s,t;
            scanf("%d%d",&s,&t);
            for(int i=1;i<=n;i++){
                dis[i]=inf;
                vis[i]=false;
            }
            priority_queue<node>q;
            for(int i=1;i<=n;i++){
                if(_w[i][s]!=0){
                    dis[i]=_w[i][s];
                    q.push({i,dis[i]});
                }
            }
            for(int i=1;i<=n;i++){
                int x=q.top().x;
                q.pop();
                if(vis[x]) continue;
                vis[x]=true;
                for(int i=1;i<=n;i++){
                    if(i==x||_dis[x][i]==-1) continue;
                    if(dis[i]>dis[x]+_dis[x][i]){
                        dis[i]=dis[x]+_dis[x][i];
                        q.push({i,dis[i]});
                    }
                }
            }
            ll ans=-1;
            for(int i=1;i<=n;i++){
                if(_w[i][t]!=0){
                    if(ans==-1) ans=dis[i]+_w[i][t];
                    else ans=min(ans,dis[i]+_w[i][t]);
                }
            }
            printf("%lld\n",ans+w[s]+w[t]);
        }
    }
    else{
        memset(_dis,-1,sizeof(_dis));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k[i];j++){
                for(int _k=1;_k<=n;_k++){
                    if(_k==i) continue;
                    if(_w[_k][a[i][j]]==0) continue;
                    if(_dis[i][_k]==-1) _dis[i][_k]=t[i][j]+_w[_k][a[i][j]];
                    else  _dis[i][_k]=min(_dis[i][_k],t[i][j]+_w[_k][a[i][j]]);
                }
            }
        }
        while(q--){
            int s,t;
            scanf("%d%d",&s,&t);
            for(int i=1;i<=n;i++){
                dis[i]=inf;
                vis[i]=false;
            }
            for(int i=1;i<=n;i++){
                if(_w[i][s]!=0){
                    dis[i]=_w[i][s];
                }
            }
            for(int i=1;i<=n;i++){
                int x=-1;
                for(int j=1;j<=n;j++){
                    if(vis[j]||dis[j]==inf) continue;
                    if(x==-1||dis[j]<dis[x]) x=j;
                }
                vis[x]=true;
                for(int i=1;i<=n;i++){
                    if(i==x||_dis[x][i]==-1) continue;
                    if(dis[i]>dis[x]+_dis[x][i]){
                        dis[i]=dis[x]+_dis[x][i];
                    }
                }
            }
            ll ans=-1;
            for(int i=1;i<=n;i++){
                if(_w[i][t]!=0){
                    if(ans==-1) ans=dis[i]+_w[i][t];
                    else ans=min(ans,dis[i]+_w[i][t]);
                }
            }
            printf("%lld\n",ans+w[s]+w[t]);
        }
    }
    return 0;
}