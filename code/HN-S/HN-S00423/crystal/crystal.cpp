#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n, m, cnt;
int a[500010], b[500010], maxa = LONG_LONG_MIN;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = n / 2;i <= n;i++){
		int x = m;
		for(int j = 1;j <= i;j++){
			if(x < (a[i] - a[j])){
				break;
			}
			x -= (a[i] - a[j]);
			cnt++;
		}
		maxa = max(maxa, cnt);
		cnt = 0;
	}
	cout << maxa;
	return 0;
}
