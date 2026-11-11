#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	int a[n+1][d+1],k[m+1],x[q+1],y[q+1],ans[q+1];
	long long t[n+1][m+1],w[m+1];
	memset(a,-1,sizeof(a));
	memset(t,-1,sizeof(t));
	memset(ans,-1,sizeof(ans));
	for(int i = 1;i <= m;i++){cin >> w[i];}
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		for(int j = 1;j <= k[i];j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	for(int r = 1;r <= q;r++){
		cin >> x[r] >> y[r];
		ans[r] = w[x[r]]+w[y[r]];
	}
	for(int r = 1;r <= q;r++){
		for(long long i = min(x[r],y[r]);i <= max(x[r],y[r]);i++){
			ans[r] += t[1][i];
		}
	}
	for(int i = 1;i <= n;i++){
		cout << ans[i] << '\n';
	}
	return 0;
}
