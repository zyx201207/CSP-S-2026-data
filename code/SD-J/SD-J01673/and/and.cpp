#include<bits/stdc++.h>
using namespace std;
long long m,n;
long long a[200005],cnt[200005]; //记录a[i]中1的个数 
long long ans; 
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	} 
	for (int i = 1; i <= n; i++){
		long long y = a[i];
		for (int j = 30; j >= 0; j--){
			long long x = pow(2,j);
			if (x <= y){
				y = y - x;
				cnt[i]++;
			}
		}
	} 
	for (int i = 2; i <= n; i++){
		for (int j = 1; j <= i; j++){
			if (cnt[j] < cnt[i]){
				long long ta = cnt[j], tb = a[j];
				cnt[j] = cnt[i];
				a[j] = a[i];
				a[i] = tb;
				cnt[i] = ta;
			} 
			else if (cnt[j] == cnt[i]){
				if (a[j] < a[i]){
					long long ta = cnt[j], tb = a[j];
					cnt[j] = cnt[i];
					a[j] = a[i];
					a[i] = tb;
					cnt[i] = ta;
				}
			}
		}
	}
	ans = a[1];
	for (int i = 2; i <= m; i++){
		ans = ans & a[i];
	}
	cout << ans;
	return 0;
}

