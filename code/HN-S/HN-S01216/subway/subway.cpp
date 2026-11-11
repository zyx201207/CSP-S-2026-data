#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e5 + 10, DT = 5e2 + 10, inf = 5e14;

struct node{
	int y, z;
};

int zc[N];
int dt[DT][DT];

vector<node> zt[N];

signed main(){
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int C, n, m, d, q;
	cin >> C >> n >> m >> d >> q;
	
	for(int i=1;i<=m;i++){
		cin >> zc[i];
	}
	
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		
		for(int j=1;j<=k;j++){
			int a, b;
			cin >> a >> b;
			
			zt[a].push_back({i, b});
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i != j){
				dt[i][j] = inf;
			}
		}
	}
	
	
	for(int k=1;k<=m;k++){
		for(auto tt1 : zt[k]){
			for(auto tt2 : zt[k]){
				dt[tt1.y][tt2.y] = min(dt[tt1.y][tt2.y], tt1.z + tt2.z);
			}
		}
	}
	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dt[i][j] = min(dt[i][j], dt[i][k] + dt[k][j]);
			}
		}
	}
	
	for(int i=1;i<=q;i++){
		int st, en;
		cin >> st >> en;
		
		int mn = inf;
		
		for(auto tt1 : zt[st]){
			for(auto tt2 : zt[en]){
				mn = min(mn, tt1.z + tt2.z + dt[tt1.y][tt2.y]);
			}
		}
		
		cout << mn + zc[st] + zc[en] << '\n';
	}
	
	return 0;	
} 
