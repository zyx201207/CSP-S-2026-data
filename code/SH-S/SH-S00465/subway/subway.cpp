#include<bits/stdc++.h>
using namespace std;

	int c,n,m,d,q;
	int w[510000],k[510],a[510][300000],t[510][300000],p[300000][510];
	bool z[510000];
	long long ans;
	
	void find(int x,int y,long long mn){
		z[x] = 1;
		if (x == y) {
			ans = min(ans,mn);
			return;
		}
		for (int i = 1;i <= sizeof(p[x]);i++){
			int pp = p[x][i];
			for (int j = 1;j <= k[pp];j++){
				if (z[a[pp][j]] == 0){
					find(a[pp][j],y,mn + t[pp][j]);
				}
			}
		}
	}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for (int i = 1;i <= n;i++){
		cin >> k[i];
		for (int j = 1;j <= k[i];j++){
			cin >> a[i][j] >> t[i][j];
			p[a[i][j]][sizeof(p[a[i][j]]) + 1] = i;
		}
	}
	for (int i = 1;i <= q;i++){
		int x,y;
		cin >> x >> y;
		for (int i = 1;i <= 501000;i++){
			z[i] = 0;
		}
		ans = d;
		find(x,y,0LL);
		cout << ans + w[x] + w[y] << endl;
	}              
	return 0;
} 
