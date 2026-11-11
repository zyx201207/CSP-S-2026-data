#include <bits/stdc++.h>
using namespace std;
#define int long long

int c, n, m, d, q, a, t;
int w[500005], k, sum, x, y;
map<pair<int, int>, int> v;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1; i<=m; i++){
		cin >> w[i];
	}
	for(int i=1; i<=n; i++){
		cin >> k;
		for(int j=1; j<=k; j++){
			cin >> a >> t;
			v[{i, a}]=t;
		}
	}
	for(int i=1; i<=q; i++){
		cin >> x >> y;
		int sum=w[x]+w[y];
		int op=1, l=x, r=x;
		for(; l<y-1 || r<y; ){
			sum+=v[{l, r}];
			if(op%2==1){
				r++;
			}else{
				l++;
			}
			op++;
		}
		sum+=v[{l, r}];
		cout << sum << "\n";
	}
	return 0;
}