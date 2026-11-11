#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int m, n, a[200001], maxn = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		
	}if (n == 1){
		cout << a[1];
		return 0;
	}for (int i = 1; i <= n - m + 1; i++){
		int j = i + m - 1;
		int b = a[i];
		for (int k = i + 1; k <= j; k++){
			b = b & a[k];
		}maxn = max(b, maxn);
	}sort(a + 1, a + n + 1);
	int b = a[n];
	for (int i = n - 1; i >= n - m + 1; i--){
		b = b & a[i];
	}maxn = max(b, maxn);
	cout << maxn;
	return 0;
}
