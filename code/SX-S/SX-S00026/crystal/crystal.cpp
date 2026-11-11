#include<bits/stdc++.h>
#define int long long
using namespace std;
int h[500010], g[500010];
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, mm;
	cin >> n >> mm;
	for(int i = 1; i <= n; i ++){
		cin >> h[i];
	}
	sort(h + 1, h + 1 + n);
	if(n > 5000){
		int ma = 1;
		for(int i = 2; i <= n; i ++){
			if(g[i - 1] + (h[i] - h[i - 1]) * (i - 1) <= mm){
				g[i] = g[i - 1] + (h[i] - h[i - 1]) * (i - 1);
				ma ++;
			}else{
				break;
			}
		}
		cout << ma;
		return 0;
	}
	int ma = 1;
	for(int i = 1; i <= n; i ++){
		int sum = 0, m = mm;
		for(int j = 1; j <= i + 1; j ++){
			if(h[i] >= h[j]){
				if(m >= h[i] - h[j]){
					sum ++;
					m -= (h[i] - h[j]);
				}
			}
		}
		ma = max(ma, sum);
	}
	cout << ma;
	return 0;
}