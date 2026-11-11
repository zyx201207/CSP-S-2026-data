//SN-J01043
#include<bits/stdc++.h>
using namespace std;
constexpr int N = 2e5 + 7;
int n, m, a[N], ans;
int sum[32], maxb = -1, lst;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out","w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		for (int j = 0; j <= 30; j++)
			sum[j] += ((a[i] >> j) & 1);
	}
	for (int j = 30; j >= 0; j--){
		if (sum[j] >= m){
			lst = maxb = j;
			break;
		}
	}
	if (maxb == -1){
		cout << '0';
		return 0;
	}
	ans += (1 << maxb);
	while (1){
		memset(sum, 0, sizeof sum);
		maxb = -1;
		for (int i = 1; i <= n; i++){
			if (((a[i] >> lst) & 1) == 0)
				a[i] = -1;
			if (a[i] == -1) continue;
			for (int j = lst - 1; j >= 0; j--)
				sum[j] += ((a[i] >> j) & 1);
		}

		for (int j = lst - 1; j >= 0; j--){
			if (sum[j] >= m){
				maxb = j;
				break;
			}
		}
		if (maxb == -1) break;
		lst = maxb;
		ans += (1 << maxb);
	}
	cout << ans << '\n';
} 
