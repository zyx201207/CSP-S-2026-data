#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, ans, a[500005], cnt[300005];
signed main(){
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)  cin >> a[i];
	for (int i = 1; i <= n; i++){
		vector <int> ta;
		for (int j = i; j <= n; j++){
			int fl = -1;
			for (int k = 0; k < ta.size(); k++){
				int x = ta[k], y = a[j];
				if (x == y){
					fl = k;
					break;
				}
			}
			if (fl == -1)  ta.push_back (a[j]);
			else{
				while (ta.size() > fl)  ta.pop_back();
				ta.push_back(a[j]);
			}
		}
		for (int j:ta)
			cnt[j]++;
	}
	for (int i = 1; i <= m; i++)  cout << cnt[i] << ' ';
	return 0;
}
