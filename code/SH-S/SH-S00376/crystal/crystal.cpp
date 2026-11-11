#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500000 + 50];
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int ans = 0;
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++){
		int tmp = 0, cnt = 1;
		for(int j = i - 1; j >= 1; j--){
			if(tmp + a[i] - a[j] <= m){
				tmp += a[i] - a[j];
				cnt++;
				//cout << tmp;
			}
			else{
				break;
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans;
	return 0;
}
