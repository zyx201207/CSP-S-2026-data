#include <bits/stdc++.h>
using namespace std;
int c, t;
long long n, d;
long long x[500010], arr[500010];
int sj1[500010], sj2[500010];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> c >> t;
	while (t --){
		int ans = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i ++){
			sj1[i] = 0;
			sj2[i] = 0;
			cin >> x[i];
		}
		for (int i = 1; i <= n; i ++){
			int l = i, r = n, mid;
			while (l <= r){
				mid = (l + r) / 2;
				if (x[mid] - x[i] <= d) l = mid + 1;
				else r = mid - 1;
			}
			arr[i] = r;
		}
		for (int i = 3; i < n; i ++){
			if (arr[i - 1] != i && arr[i - 2] == i){
				sj1[i - 2] ++;
				if (arr[i - 1] == i + 1) sj2[i + 1] ++;
			}
		}
		for (int i = 1; i <= n; i ++){
			if (sj1[i] == 1){
				for (int j = i; j >= 1; j --){
					if (arr[j] == i + 2) sj1[i] ++;
					else break;
				}
				for (int j = i; j >= 1; j --){
					if (arr[j] == i) sj1[i] ++;
					else break;
				}
			}
			if (sj2[i] == 1){
				if (arr[i + 1] != arr[i]) sj2[[arr[i]] += arr[i + 1] - arr[i];
			}
		}
		for (int i = 2; i < n; i ++){
			ans += sj1[i - 1] * sj2[i + 1];
		} 
		cout << ans << " ";
	}
	return 0;
} 
