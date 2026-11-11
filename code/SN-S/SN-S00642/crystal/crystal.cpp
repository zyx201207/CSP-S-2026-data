#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 500005;
int n, m, g[N], ans;
bool cmp(int p1, int p2){
	return p1 > p2;
}
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		cin >> g[i];
	}
	sort(g + 1, g + 1 + n, cmp);
	for(int i = 1; i <= n; ++i){
		int a = m;
		int cnt = 0;
		for(int j = i; j <= n; ++j){
			if(a - (g[i] - g[j]) >= 0){
				a -= g[i] - g[j];
				cnt++;
				ans = max(ans, cnt);
			}else{	
				break;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
