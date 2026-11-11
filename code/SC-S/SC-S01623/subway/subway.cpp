#include <bits/stdc++.h>
using namespace std;
struct Node{
	vector <int> e;
	vector <int> t;
};
Node k[505];
int s[500005];
int N;
long long dfs(int n, int m){
	int a[505], b[505];
	int a3, b3;
	int a2 = 0, b2 = 0;
	for (int i = 1; i <= N; i++){
		for (int j = 0; j < k[i].e.size(); j++){
		if (k[i].e[j] == n){
			a[a2++] = i;
			a3 = j;
		}
		if (k[i].e[j] == m){
			b[b2++] = i;
			b3 = j;
		}
		if (a[a2] == b[b2])
		return (k[i].t[n] + k[i].t[m]);
		return dfs(k[i].e[a3+1], k[i].e[b3+1]);
	}
	}
}
int main(){
	int c, n, m, d, q;
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	N = n;
	for (int i = 1; i <= m; i++) cin >> s[i];
	for (int i = 1; i <= n; i++){
		int k_p;
		cin >> k_p;
		for (int j = 1; j <= k_p; j++){
			int a, t;
			cin >> a >> t;
			k[i].e.push_back(a);
			k[i].t.push_back(t);
		}
	}
	for (int i = 1; i <= q; i++){
		int ins, outs;
		cin >> ins >> outs;
		cout << (s[n] + s[m] + dfs(ins, outs));
	}
	return 0;
}