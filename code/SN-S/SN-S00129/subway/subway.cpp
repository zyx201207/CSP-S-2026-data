#include <bits/stdc++.h>
using namespace std;
//!!!!!!
//
//
//Ã»ÓÐ¿ªlong long 
const int N = 5e5+10;

struct node{
	int v;
	long long w;
};

int c,n,m,d,q;
long long w[N];
long long dist[510],a[510][510],mn[510][510];
int vis[510];
int de[N][21],cnt[N];
int time1[N][21];
vector <node> b[510];

void djk(int start){
	for(int i=1;i<=n;i++){
		dist[i] = 1e18;
		vis[i] = 0;
	}
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	dist[start] = 0;
	q.push({0,start});
	while(!q.empty()){
		int u = q.top().second;
		q.pop();
		if(vis[u])continue;
//		cout << u << " " << dist[u] << "\n";
		vis[u] = 1;
		for(auto & j : b[u]){
			int v = j.v;
			int w = j.w;
//			cout << u << " " << i << " : " << dist[i] <<" - " << dist[u]+a[u][i]<< "\n"; 
			if(dist[v]>dist[u]+w){
				dist[v] = dist[u]+w;
				if(!vis[v])q.push({dist[v],v});
			}
		}
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin >> x >> y;
			de[x][++cnt[x]] = i;
			time1[x][cnt[x]] = y;
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j)a[i][j] = 1e18;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=cnt[i];j++){
			for(int g=1;g<j;g++){
				a[de[i][j]][de[i][g]] = min(a[de[i][j]][de[i][g]],(long long)time1[i][j]+(long long)time1[i][g]);
				a[de[i][g]][de[i][j]] = min(a[de[i][g]][de[i][j]],(long long)time1[i][j]+(long long)time1[i][g]);
				mn[de[i][j]][de[i][g]] = a[de[i][j]][de[i][g]];
				mn[de[i][g]][de[i][j]] = a[de[i][j]][de[i][g]];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j&&a[i][j]!=1e18){
				b[i].push_back({j,a[i][j]});
			}
		}
	}
	for(int i=1;i<=n;i++){
		djk(i);
		for(int j=1;j<=n;j++){
			mn[i][j] = dist[j];
		}
//		for(int k=1;k<=n;k++){
//			for(int j=1;j<=n;j++){
//				
//			}
//		}
	}
	
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout << a[i][j] << " " << mn[i][j] << "\n";
//		}
//	}
	for(int i=1;i<=q;i++){
		int x,y;
		long long sum = 1e18;
		cin >> x >> y;
		for(int j=1;j<=cnt[x];j++){
			for(int g=1;g<=cnt[y];g++){
				sum = min(sum,mn[de[x][j]][de[y][g]]+(long long)time1[x][j]+(long long)time1[y][g]+w[x]+w[y]);
			}
		}
		cout << sum << "\n";
	}
	return 0;
}
