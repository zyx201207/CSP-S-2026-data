#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	string s;
	long long n, m, a[200005], maxn = -9999999;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = i+1; j <= n; j++){
			maxn = max(a[i] & a[j], maxn);
		}
	}
	cout << maxn;
	return 0;
} 
