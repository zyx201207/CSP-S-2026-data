#include<bits/stdc++.h>
#define int long long

using namespace std;
int c, n, m, d, q;
int w[500005],t,a, k[505];
struct node{
	int stat, tim;
};
vector <node> g[505];
int ans[100005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++){
		scanf("%lld",&w[i]);
	}
	for(int i = 1; i <= n; i ++){
		scanf("%lld", &k[i]);
		for(int j = 1; j <= k[i]; j ++){
			scanf("%lld %lld", &a, &t);
			ans[i] += t;
			g[i].push_back({a, t});
			
			
			
		}
	}
	int x, y;
	for(int i = 1; i <= q; i ++){
		cin >> x >> y;
		cout << ans[i] + w[x] + w[y] << endl;
	}
	
	return 0;
}

