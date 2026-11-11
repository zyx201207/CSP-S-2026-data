#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q, w[500005], k[505], x[100005], y[100005];
vector<int> a[505], t[505];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin >> c >> n >> m >> d >> q;
	for(int v = 1;v <= m;v++) cin >> w[v];
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		for(int j = 1;j <= k[i];j++){
			int ax, tx;
			cin >> ax >> tx;
			a[i].push_back(ax);
			t[i].push_back(tx);
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
