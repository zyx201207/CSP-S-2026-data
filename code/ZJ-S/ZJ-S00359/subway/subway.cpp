#include <bits/stdc++.h>
using namespace std;
struct cpp{
	int t;
	int nt;
	int ti;
	int bti;
};
int c, n, m, d, qq, w[500005];
vector<cpp> z[500005];
int qx, zx;
int mxt = INT_MAX;
bool vis[500005];
void dfs(int x, int nt, int t){
	if(x == zx){
		for(int i = 0; i < z[x].size(); ++i){
			if(z[x][i].nt == nt){
				mxt = min(t + z[x][i].bti, mxt);
		        return;
			}
		}
		
	}
	for(int i = 0; i < z[x].size(); ++i){
		int nx = z[x][i].t;
		if(vis[nx] == 1){
			continue;
		}
		int ttt = t;
		if(nt != z[x][i].nt){
			int bti;
			for(int i = 0; i < z[x].size(); ++i){
				if(nt == z[x][i].nt){
					bti = z[x][i].bti;
					break;
				}
			}
			ttt += (z[x][i].ti + bti);
			if(ttt > mxt){
				continue;
			}
			vis[nx] = 1;
		    dfs(nx, z[x][i].nt, ttt);
		    vis[nx] = 0;
		}else{
			vis[nx] = 1;
			dfs(nx, nt, t);
			vis[nx] = 0;
		}
	}
}
int t[500005], ti[500005];
int main(){
	cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> qq;
	for(int i = 1; i <= m; ++i){
		cin >> w[i];
	}
	for(int i = 1; i <= n; ++i){
		int k;
		cin >> k;
		for(int j = 1; j <= k; ++j){
			cin >> t[j] >> ti[j];
			
		}
		for(int j = 1; j <= k; ++j){
			if(j == 1){
				z[j].push_back(cpp{t[j + 1], i, ti[j + 1], ti[j]});
			}else if(j == k){
				z[j].push_back(cpp{t[j - 1], i, ti[j - 1],ti[j]});
			}else{
				z[j].push_back(cpp{t[j + 1], i, ti[j + 1], ti[j]});
				z[j].push_back(cpp{t[j - 1], i, ti[j - 1], ti[j]});
			}
		}
	}
	for(int i = 1; i <= qq; ++i){
		cin >> qx >> zx;
		for(int j = 0; j <= z[qx].size(); ++j){
			vis[qx] = 1;
		    dfs(qx,z[qx][j].nt, w[qx] + w[zx] + z[qx][j].bti);
		    for(int i = 1; i <= n; ++i){
		    	vis[i] = 0;
			}
	    }
	    cout << mxt << "\n";
	    mxt = INT_MAX;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}