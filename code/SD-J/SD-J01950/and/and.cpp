#include <bits/stdc++.h>
using namespace std;
int a[2000006];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int maxn = 1;
	for(int i = 1; i <= n; i++){
		maxn = max(a[i], maxn);
	}
	cout << maxn;
}
