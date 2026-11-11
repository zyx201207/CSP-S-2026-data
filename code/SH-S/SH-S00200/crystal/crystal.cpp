#include <bits/stdc++.h>
using namespace std;
long long a[500001], n, m, k, s;
bool cmp(int u, int v){ return u > v;}
int main(){
	cin.tie(0), cout.tie(0);
//	freopen("crystal.in", "r", stdin);
//	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1, cmp);
	int k = n / 2 + 1;
	for (int i = k + 1; i <= n; i++){
		while (a[i] != a[k]) m--, a[i]++;
	}
	for (int i = 1; i <= n; i++)
		if (a[i] == a[k]) s++;
	cout << s;
	return 0;
} 
