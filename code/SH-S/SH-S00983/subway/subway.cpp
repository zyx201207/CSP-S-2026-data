#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int T;
struct node{
	int x, s;
};
int c, n, m, d, q, k, x, y, ans = 500005;
int w[500005], vis[250000005];
vector <int> a[25000005];
void f(int x, int sum){
	if(x == y){
		ans = min(ans, sum);
	}
	vis[x] = 1;
	for(int i = 0;i < a[x].size();i++){
		long long t = a[x][i];
		if(!vis[t]){
			if(t >= N){
				sum++;
			}
			f(t, sum);
		}
	}
	vis[x] = 0;
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 0;i < m;i++){
		cin >> w[i];
	}
	int t;
	for(int i = 1;i <= n;i++){
		cin >> k;
		for(int j = 0;j < k;j++){
			cin >> x >> T;
			a[x].push_back(i * N);
			a[i * N].push_back(x);
			t = x;
		}
	}
	while(q--){
		cin >> x >> y;
		memset(vis, 0, sizeof(vis));
		ans = 500005;
		f(x, 0);
		cout << w[x] + w[y] + T * (ans - 1) << endl;
	}
	return 0;
} 
