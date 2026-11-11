#include<bits/stdc++.h>
using namespace std;
int n, m, c, q,x, y, zz, zzz;
int w[500005], k[505];
vector<int> a[505];
vector<int> t[50005];
int p[100005], z[100005];
int d[2005][2005];
void dis(){
	for(int i = 1; i <= m; i++){
		d[i][i] = 0x3f;
	}
	for(int k = 1; k <= m; k++){
		for(int i = 1; i <= m; i++){
			for(int j = 1; j <= m; j++){
				d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> zzz >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		zz += k[i];
		for(int j = 1; j <= k[i]; j++){
			cin >> x >> y;
			a[x].push_back(y);
			a[y].push_back(x);
			t[j].push_back(y);
		}
	}
	for(int i = 1; i <= q; i++){
		cin >> p[i] >> z[i];
	}
	void dis();
	int ans;
	for(int i = 1; i <= q; i++){
		ans = d[p[i]][z[i]];
		ans +=  w[p[i]] + w[z[i]]; 
		cout << ans << endl;
		ans = 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
