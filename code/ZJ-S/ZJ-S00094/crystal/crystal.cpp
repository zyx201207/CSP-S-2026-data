#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m, a[500001], sum = 0, cnt = 0, maxn = -1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}if (n == 1){
		cout << 1;
		return 0;
	}sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++){
		int j = i, cnt = 1, sum = 0;
		while (sum <= m && j < n){
			j++;
			sum += (j - i) * (a[j] - a[j - 1]);
			if (sum > m){
				cnt += 0;
			}else {
				cnt++;
			}
		}maxn = max(maxn, cnt);
	}cout << maxn;
	return 0;
}
