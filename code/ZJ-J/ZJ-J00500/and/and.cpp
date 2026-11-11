#include<bits/stdc++.h>
using namespace std;
long long int a[200015];
int n , m;
long long int dfs(int p , long long int num , int rest) {
	if (p > n && rest > 0) return -1;
	else if (rest == 0) return num;
	else {
		long long int ansa = 0 , ansb = 0;
		if (rest == m) {
			ansa = dfs(p + 1 , 0 , rest);
			ansb = dfs(p + 1 , a[p] , rest - 1);
		}
		else {
			ansa = dfs(p + 1 , num , rest);
			ansb = dfs(p + 1 , num & a[p] , rest - 1);
		}
		mp[p] = max(ansa , ansb);
		return max(ansa , ansb);
	}
}
int main () {
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cout << dfs(1 , 0 , m) << "\n";
	return 0;
}
