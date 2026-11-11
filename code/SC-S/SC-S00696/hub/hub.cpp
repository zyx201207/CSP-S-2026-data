#include <bits/stdc++.h>
using namespace std;

int c, t, f[200010], n, k, ans, g, x, q[200010];
vector <int> rode[200010];

void paint (int i, int h, int fr){
	f[i]++;
	if (f[i] == 1)
		g++;
	if (h == x)
		return ;
	for (auto y : rode[i]){
		if (y != fr)
			paint (y, h + 1, i);
	}
}

void clean (int i, int h, int fr){
	f[i]--;
	if (f[i] == 0)
		g--;
	if (h == x)
		return ;
	for (auto y : rode[i]){
		if (y != fr)
			clean (y, h + 1, i);
	}
}

void dfs (int i, int p){
	if (i == n + 1){
		if (g == n){
			ans = 1;
//			for (int j = 1; j <= n; j++)
//				printf ("%d ", q[j]);
//			printf ("\n");
		}
		return ;
	}
	if (p == k){
		return ;
	}
	q[i] = 0;
	dfs (i + 1, p);
	if (ans == 1)
		return ;
	q[i] = 1;
	paint (i, 0, 0);
	dfs (i + 1, p + 1);
	clean (i, 0, 0);
	if (ans == 1)
		return ;
}

int main (){
	freopen ("hub.in", "r", stdin);
	freopen ("hub.out", "w", stdout);
	scanf ("%d%d", &c, &t);
	for (; t; t--){
		scanf ("%d%d", &n, &k);
		for (int i = 1; i <= n; i++){
			rode[i].clear ();
		}
		for (int i = 1; i <= n; i++){
			int a, b;
			f[i] = 0;
			scanf ("%d%d", &a, &b);
			rode[a].push_back (b);
			rode[b].push_back (a);
		}
		int l = 0, r = n, m = (l + r) / 2;
		while (l + 1 < r){
			x = m;
			ans = 0;
			dfs (1, 0);
			if (ans){
				r = m;
			}
			else{
				l = m;
			}
			m = (l + r) / 2;
		}
		printf ("%d\n", r);
	}
	return 0;
}