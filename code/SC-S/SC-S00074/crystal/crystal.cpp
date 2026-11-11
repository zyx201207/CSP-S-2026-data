#include <bits/stdc++.h>
using namespace std;
int a[500001];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	int ma = 0;
	sort(a, a + n);
	for (int i = 0; i < n - 1; i++){
		long long z = 0;
		int c = 0;
		for (int j = i + 1; j < n; j++){
			if (z + (a[i + 1] - a[i]) * (c + 1) <= m){
				z += (a[i + 1] - a[i]) * (c + 1);
				c++;
			}else{
				break;
			}
		}
		ma = max(ma, c);
	}
	cout << ma;
}
