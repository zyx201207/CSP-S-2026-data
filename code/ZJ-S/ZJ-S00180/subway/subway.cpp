#include<bits/stdc++.h>
using namespace std;
#define ll long long
int  testcase,n,m,d,T;
int w[500005],k[500005],a[505][20005],t[505][20005];
ll dis[500005];
int li[500005];
bool vis[500005];
vector<pair<int,int>> G[5000005];
void dfs(int v,int wli){
    for(auto it:G[v]){
        int u=it.first,op=it.second;
        if(vis[u])continue;
        vis[u]=1;
        if(op!=wli){
            G[v][u].second=t[op][u]+t[wli][u];
        }else{
            G[v][u].second=0;
        }
        dfs(u,op);
    }
}
void dijkstra(int s){
    memset(dis,0x3f,sizeof dis);
    memset(vis,0,sizeof vis);
    dis[s]=0;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    pq.push({0,s});
    while(!pq.empty()){
        int d=pq.top().first,u=pq.top().second;
        pq.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(auto it:G[u]){
            int v=it.first,w=it.second;
            if(vis[v])continue;
            if(dis[u]>dis[v]+w){
                dis[u]=dis[v]+w;
                pq.push({dis[v]+w,v});
            }
        }
    }
}
int main(){
	freopen("subway.in ","r",stdin);
    freopen("subway.out ","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin>>testcase>>n>>m>>d>>T;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][a[i][j]];
            li[a[i][j]]=i;
            if(j>1)G[a[i][j-1]].push_back({a[i][j],i});
        }
    }
    for(int i=1;i<=m;i++){
        if(!vis[i]){
        	vis[i]=1;
        	dfs(i,li[i]);	
		}
    }
    while(T--){
        int st,ed;
        cin>>st>>ed;
        dijkstra(st); 
        cout<<w[st]+w[ed]+dis[ed]<<endl;  
    }
	return 0;
}