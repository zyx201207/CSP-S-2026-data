#include<bits/stdc++.h>
using namespace std;

long long c,n,m,d,qq;
long long f[50005][505],k[505],dis[505][505],w[500005];
vector<pair<int,long long>>out[500005];
///*
struct node{
	int now;
	long long d;
	bool operator<(const node& x)const{
		return d>x.d;
	}
};
//*/
priority_queue<node>q;
bool vis[505];

int main(){
	///*
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> qq;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	
	for(int i=1;i<=n;i++){
		cin >> k[i];
		for(int j=1;j<=k[i];j++){
			long long v,t;
			cin >> v >> t;
			out[v].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=1e18;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dis[i][j]=1e18;
		}
	}
	//cout << "hdhd" << endl;
	for(int i=1;i<=m;i++){
		for(pair<int,long long>x : out[i]){
			int v1=x.first;
			long long t1=x.second;
			for(pair<int,long long>y : out[i]){
				int v2=y.first;
				long long t2=y.second;
				if(v1==v2)continue;
				dis[v1][v2]=dis[v2][v1]=min(dis[v1][v2],t1+t2);
			}
		}
	}
	//cout << "ok" << endl;
	for(int i=1;i<=m;i++){
		for(pair<int,long long>x : out[i]){
			f[i][x.first]=x.second;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++)vis[j]=0;
		while(!q.empty())q.pop();
		for(int j=1;j<=n;j++){
			if(f[i][j]!=1e18){
				q.push({j,f[i][j]});
			}
		}
		while(!q.empty()){
			node x=q.top();q.pop();
			if(vis[x.now])continue;
			vis[x.now]=1;
			for(int j=1;j<=n;j++){
				long long t=dis[x.now][j];
				if(f[i][x.now]+t<f[i][j]){
					f[i][j]=f[i][x.now]+t;
					q.push({j,f[i][j]});
				}
			}
		}
	}
	
	while(qq--){
		int u,v;
		cin >> u >> v;
		long long ans=1e18;
		for(pair<int,long long>y : out[v]){
			int x=y.first;
			long long t=y.second;
			ans=min(ans,f[u][x]+t+w[u]+w[v]);
		}
		cout << ans << endl;
	}
	//*/
}