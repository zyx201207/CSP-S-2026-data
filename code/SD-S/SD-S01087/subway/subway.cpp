#include<bits/stdc++.h>
using namespace std;

#define int long long 

const int N = 5e2 + 11,M = 5e5 + 11;

int c,n,m,d,q,sum,T;

int k[N],w[M];
vector<int>t[N];
vector<int>a[N];

vector<pair<int,int>> idx[M];

int dis[N * 2][N * 2];
int dp[511][511];

void solve_1(){
	for(int i = 1;i <= m;i ++){
		for(int j = 1;j <= m;j ++){
			dis[i][j] = 1e14;
		}
		dis[i][i] = 0;
	}
	

	for(int i = 1;i <= m;i ++){
		for(auto j:idx[i]){
			int na = j.first;
			int w = j.second;
			for(int l = 0;l < k[na];l ++){
				
				dis[i][a[na][l]] = min(dis[i][a[na][l]],w + t[na][l]);
			}
		}
	}
	
	for(int i = 1;i <= m;i ++){
		for(int l = 1;l <= m;l ++){
			for(int j = 1;j <= m;j ++){
				dis[i][j] = min(dis[i][l] + dis[l][j],dis[i][j]);
			}
		}
	}
	
	for(int i = 1;i <= m;i ++){
		for(int j = 1;j <= m;j ++){
			dis[i][j] += w[i] + w[j];
		}
	}
	
//	for(int i = 1;i <= m;i ++){
//		for(int j = 1;j <= m;j ++){
//			cout << dis[i][j] << " ";
//		}
//		cout << "\n";
//	}
//	
	while(q --){
		int x,y;
		cin >> x >> y;
		cout << dis[x][y] << "\n";
	}
	
	return;
}

void solve_2(){
	
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= n;j ++){
			dp[i][j] = 1e14;
		}
	}
	for(int i = 1;i <= m;i ++){
		for(auto j:idx[i]){
			for(auto l:idx[i]){
				if(j.first != l.first)
					dp[j.first][l.first] = dp[l.first][j.first] = 1;
			}
		}
	}
	
	for(int i = 1;i <= n;i ++){
		for(int l = 1;l <= n;l ++){
			for(int j = 1;j <= n;j ++){
				dp[i][j] = min(dp[i][l] + dp[l][j],dp[i][j]);
			}
		}
	}
	

	
	while(q --){
		int x,y;
		cin >> x >> y;
	
		int ans = 1e14;
		for(auto j:idx[x]){
			for(auto l:idx[y]){
				if(j.first == l.first)
					ans = min(ans,2 * T);
				else
					ans = min(ans,T * 2 + 2 * T * dp[j.first][l.first]);
			}
		}
		cout << ans + w[x] + w[y] << "\n";
	}
	
}

signed main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> c >> n >> m >> d >> q;
	
	for(int i = 1;i <= m;i ++)
		cin >> w[i];
		
	for(int i = 1;i <= n;i ++){
		cin >> k[i];
		for(int j = 1;j <= k[i];j ++){
			int x,y;
			cin >> x >> y;
			T = y;
			a[i].push_back(x);
			t[i].push_back(y);
			idx[x].push_back({i,y});
		}
	}
	
	if(c <= 11)
		solve_1();
	
	else
		solve_2();
	return 0;
}





