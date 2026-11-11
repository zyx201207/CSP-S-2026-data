#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=50010;
vector<int> g[N];
ll tim[N];
ll a[510][50010],t[510][50010];
ll dis[10010];
bool vis[500010];
int c,n,m,d,q;
void init(){
	for(int i=1;i<=n;i++){
		dis[i]=1e18;
	}
}
void dj(int st){
	for(int i=1;i<=m;i++){
		dis[i]=1e18;
	}
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
	pq.push({0,st});
	dis[st]=0;
	while(!pq.empty()){
		int u=pq.top().second;
		if(vis[u]){
			continue;
		}
		vis[u]=true;
		pq.pop();
		//cout<<g[u].size()<<"\n";
		
		for(int j=0;j<(int)g[u].size();j++){
			//cout<<j<<"\n";
			int v=g[u][j];
			bool fl=false;
			//cout<<u<<" "<<v<<"\n"; 
			
			for(int i=1;i<=n;i++){
				
				if(t[i][u]!=0&&t[i][v]!=0){
					
					//cout<<u<<" "<<v<<" 1\n";
					fl=true;
					dis[v]=dis[u];
					cout<<dis[v]<<" "<<v<<" 10086\n";
					pq.push({dis[v],v});
					break;
					
				}
			}
			
			if(!fl){
				ll mn1=1e18,mn2=1e18;
				for(int z=1;z<=n;z++){
					mn1=min(mn1,t[z][u]);
				}
				for(int z=1;z<=n;z++){
					mn2=min(mn2,t[z][v]);
				}
				if(dis[v]>dis[u]+mn1+mn2){
					//cout<<u<<" "<<v<<" 2\n";
					dis[v]=dis[u]+mn1+mn2;
					pq.push({dis[st][v],v});
				}
			}
			
		}
		
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	init();
	for(int i=1;i<=m;i++){
		cin>>tim[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
		for(int j=2;j<=k;j++){
			g[a[i][j]].push_back(a[i][j-1]);
			g[a[i][j-1]].push_back(a[i][j]);
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		init();
			dj(x);
			cout<<dis[y]+tim[x]+tim[y]<<"\n";
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
