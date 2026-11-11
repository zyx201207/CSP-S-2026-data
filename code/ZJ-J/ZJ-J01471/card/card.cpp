#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10, M = 3e5 + 10;
int n, m;
int a[N], lst[M], num[M];
int cnt[M];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	for(int i = n; i > 0; i --)
		lst[a[i]] += (!lst[a[i]]) * i, 
		num[a[i]] ++;
	for(int i = 1; i <= m; i ++)
		for(int x = i; x > 0; x = a[lst[x] + 1])
			cnt[x] += num[i];
	for(int i = 1; i <= m; i ++)
		cout << cnt[i] << " ";
	cout << endl;
	
	return 0;
}
