#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int n,gay,m,d,q,x,y,w[500050],kk,e[500050][550];
long long res[550][550];
vector<int> ve[500050];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(res,0x3f,sizeof(res));
	cin >> gay >> n >> m >> d >> q;
	for(int i = 1;i <= m;i ++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i ++){
		cin >> kk;
		res[i][i] = 0;
		if(kk == 1){
			continue;
		}
		for(int j = 1;j <= kk;j ++){
			int u,ww;
			cin >> u >> ww;
			ve[u].push_back(i);
			e[u][i] = ww;
		}
	}
	for(int i = 1;i <= m;i ++){
		for(int j = 0;j < ve[i].size();j ++){
			for(int k = 0;k < ve[i].size();k ++){
				if(j == k){
					continue;
				}
				res[ve[i][j]][ve[i][k]] = min(res[j][k],(long long)e[i][ve[i][j]] + e[i][ve[i][k]]);
			}
		}
	}
		for(int k = 1;k <= n;k ++){
			for(int i = 1;i <= n;i ++){
			if(i == k){
				continue;
			}
				for(int j = 1;j <= n;j ++){
					if(j == 1 || j == k){
						continue;
					}
					res[i][j] = min(res[i][j],res[i][k] + res[k][j]);
				}
			}
		}
	while(q--){
		cin >> x >> y;long long tt = 1e18;
		for(int i = 0;i < ve[x].size();i ++){
			for(int j = 0;j < ve[y].size();j ++){
				int v1 = ve[x][i];
				int v2 = ve[y][j];
				tt = min(tt,res[v1][v2] + e[x][v1] + e[y][v2]);
			}
		}
		cout << tt + w[x] + w[y] << endl;
	}
	return 0;
}

