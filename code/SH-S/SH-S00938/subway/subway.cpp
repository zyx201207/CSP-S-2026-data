#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[500010],t[510][20010];
vector<int> a[510];
vector<int> a2[500010];
long long dis[500010];
int pre[500010];
bool vis[500010];
struct T{
	int u;
	long long val;
};
struct cmp{
	bool operator()(const T&x,const T&y){
		return x.val>y.val;
	}
};
priority_queue<T,vector<T>,cmp> pq;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x;
			cin>>x;
			a[i].push_back(x);
			a2[x].push_back(i);
			cin>>t[i][x];
		}	
	}
	while(q--){
		memset(vis,0,sizeof(vis));
		while(!pq.empty()) pq.pop();
		int x,y;
		cin>>x>>y;
		for(int i=1;i<=m;i++) dis[i]=1e18;
		dis[x]=0;
		pq.push(T{x,0});
		while(!pq.empty()){
			int u=pq.top().u;pq.pop();
			if(vis[u]) continue;
			if(u==y) break;
			vis[u]=1;
			for(int i=0;i<(int)a2[u].size();i++){
				int mid=a2[u][i];
				for(int j=0;j<(int)a[mid].size();j++){
					int v=a[mid][j];
					if(!vis[v]){
						if(dis[u]+t[mid][u]+t[mid][v]<dis[v]){
							dis[v]=dis[u]+t[mid][u]+t[mid][v];
							pre[v]=u;
							pq.push(T{v,dis[v]});
						}
					}
				}
			}
		}
		cout<<w[x]+w[y]+dis[y]<<"\n";
	}
	return 0;
}
