#include <bits/stdc++.h>
#define ll long long
#define mp make_pair()
using namespace std;
int a[1000000], fa[1000000];

int find(int a) {
	//if(a=fa[a]) return fa[a];
	fa[a] = fa[fa[a]];
	return fa[a];
}

void connect(int a, int b) {
	int q = find(a);
	int p = find(b);
	fa[a] = fa[b];
}

int main() {
	int none, t, m, n, i, j, k, last = 100000, a, b;
	cin >> none >> t;

	for (i = 0; i < t; i++) {
		cin >> n >> k;
		for (i = 1; i < n; i++) {
			cin << a << b;
			connect(a, b);
		}
	}
	for (i = 0; i < n; i++) {
		for (j = i + k; j < )
		}
}