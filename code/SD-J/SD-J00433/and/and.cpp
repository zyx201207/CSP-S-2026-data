#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n , m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int maxn = 0;
	for (int i = 1; i <= n; i++){
		for (int j = i; j <= n; j++){
			int ans = a[i] && a[j];
			if (ans > maxn) maxn = ans;
		}
	}
	cout << maxn;
	return 0;
}

