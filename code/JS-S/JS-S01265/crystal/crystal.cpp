#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5 + 5;
int n, m;
int a[N];

struct Count{
	int val;
	int cnt;
};

Count s[N];

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1, j = 1; i <= n; ++i){
		if (i == 1){
			s[j].val = a[i];
			s[j].cnt++;
		}else if (a[i] == s[j].val){
			s[j].cnt++;
		}else{
			j++;
			s[j].cnt++;
			s[j].val = a[i];
		}
	}
	for (int i = 1; i < n; ++i){
		if ((s[i + 1].val - s[i].val) * s[i].cnt > m){
			m /= (s[i + 1].val - s[i].val);
			cout << max(s[i].cnt, s[i + 1].cnt + m) << '\n';
			return 0;
		}else{
			s[i + 1].cnt += s[i].cnt;
			m -= (s[i + 1].val - s[i].val) * s[i].cnt;
		}
	}
	cout << n << '\n';
	
	return 0;
}
