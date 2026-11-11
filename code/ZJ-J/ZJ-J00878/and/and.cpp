#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n;
long long a[N];
long long re;
long long dfs(long long d , int x , int m) {
	if(x >= n || n - x + 1 < m || m == 0) {
		if(d == re || m != 0) return 0;
		return d;
	}
	return max(dfs(d & a[x] , x + 1 , m - 1) , dfs(d , x + 1 , m));
}
int main() {
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int m;
	cin >> n >> m;
	re = 1;
	for(int i = 1;i <= 30;i++) {
		re *= 2;
	}
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	cout << dfs(re , 1 , m);
	return 0;
}
