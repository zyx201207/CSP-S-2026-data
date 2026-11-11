#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>
#define ll long long

using namespace std;

const int INF = 0x3f3f3f3f; 
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	bool flagA = 1, flagB = 1;
	int T = INF;
	cin>>c>>n>>m>>d>>q;
	vector<int> w(m+1);
	vector<vector<pair<int,int>>> side(n+m+1);
	vector<vector<ll>> g(n+1, vector<ll> (n+1, LINF));
	vector<vector<int>> path(n+1, vector<int> (n+1,-1));
	for (int i=1;i<=m;i++) cin>>w[i];
	for (int i=1;i<=n;i++){
		int ki;
		cin>>ki;
		if(ki>2) flagA = 0;
		while (ki--){
			int a,t;
			cin>>a>>t;
			side[i].push_back({n+a,t});
			side[n+a].push_back({i,t});
		}
	}
	for (int i=1;i<=n;i++){
		for (auto p : side[i]){
			if (p.first == i) continue;
			for (auto nextp : side[p.first]){
				if (nextp.first == i) continue;
				g[i][nextp.first] = min(g[i][nextp.first],(ll)(nextp.second+p.second));
			}
		}
	}
	for (int i=1;i<=n;i++){
		for (int j = 1;j<=n;j++){
			if (g[i][j]!=LINF) path[i][j] = i; 
		}
	}
	for (int mid=1;mid<=n;mid++){
		g[mid][mid] = 0;
		for (int i=1;i<=n;i++){
			if (i==mid) continue;
			for (int j=1;j<=n;j++){
				if (j==mid) continue;
				if (g[i][j]>g[i][mid]+g[mid][j]){
					g[i][j] = g[i][mid]+g[mid][j]; 
				}
			}
		}
	}
	while (q--){
		int x,y;
		cin>>x>>y;
		long long ans = LINF; 
		for(auto p1 : side[n+x]){
			for (auto p2 : side[n+y]){
				ans = min(ans,g[p1.first][p2.first]+p1.second+p2.second);
			}
		}
		cout<<ans+w[x]+w[y]<<"\n";
	}
}
