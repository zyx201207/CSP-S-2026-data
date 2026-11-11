#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pli=pair<ll,int>;
const int maxm=5e5+5,maxn=5e2+5;
int c,n,m,d,q;
ll w[maxm],dis[1005][1005];
bool vis[1005];
struct station{
	ll u,t;
};
vector<vector<int>> l;
ll arr[1005][1005];
vector<vector<int>> go;
void dijks(int s){
	priority_queue<pli> q;
	q.push({0,s});
	while(!q.empty()){
		ll d=-q.top().first;
		int u=q.top().second;
		q.pop();
		for(auto v:go[u]){
			if(vis[v])continue;
			vis[v]=1;
			if(d+arr[u][v]<dis[s][v]){
				dis[s][v]=d+arr[u][v];
				q.push({-dis[s][v],v});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int k;
	l.resize(n+1);
	go.resize(1006);
	for(int i=1;i<=1004;i++){
		for(int j=1;j<=1004;j++){
			arr[i][j]=dis[i][j]=1e16;
		}
	}
	for(int i=1;i<=n;i++){
		dis[i][i]=arr[i][i]=0;
		cin>>k;
		int a;
		ll t;
		unordered_map<int,int> p;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			if(l[i].size()>=1){
				for(auto v:l[i]){
					arr[a][v]=arr[v][a]=min(arr[a][v],t+p[v]);
					go[a].push_back(v);
					go[v].push_back(a);
				}
			}
			p[a]=t;
			l[i].push_back(a);
		}
	}
	for(int i=1;i<=m;i++){
		for(int i=1;i<=1004;i++){
			vis[i]=0;
		}
		dijks(i);
	}
	for(int i=1;i<=q;i++){
		int s,e;
		cin>>s>>e;
		cout<<dis[s][e]+w[s]+w[e]<<'\n';
	}
	return 0;
}