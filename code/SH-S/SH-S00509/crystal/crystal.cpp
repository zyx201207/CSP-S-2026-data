#include<bits\stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int s[N], pre[N];
signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout); 
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> s[i];
	}
	sort(s + 1, s + n + 1);
	int now = 0;
	int ans = 1;
	for (int i = 1, j = 1; i <= n; i++){
		now -= s[j] - s[i];
		while (now <= m && j <= n){
			ans = max(ans, j - i + 1);
			j++;
			now += (j - i) * (s[j] - s[j-1]);
			if (now <= m)ans = max(ans, j - i + 1);
		}
	}
	cout << ans << endl;
	return 0;
}
