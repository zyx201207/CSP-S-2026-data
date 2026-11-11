#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ull N = 2e5+10;
ull n, m;
ull a[N];
ull ans = 0;
void dfs(ull used, ull now, ull x){
	if(used == m){
		ans = max(ans, x);
//		cout << now << "    ";
//		for(int i=1;i<=n;i++){
//			if((now & (1<<(i-1))) == 1) cout << a[i] << " ";
//		}
//		cout << "	" << x;
//		cout << "\n";
		return;
	}
	for(ull i=1;i<=n;i++){
		if((now & (1<<(i-1))) == 0){
			dfs(used+1, now|(1<<(i-1)), x&a[i]);
		}
	}
	return;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(ull i=1;i<=n;i++) cin >> a[i];
	if(m == n){
		ull x;
		for(int i=1;i<=n;i++) x &= a[i];
		cout << x << "\n";
		return 0;
	}
	dfs(0, 0, -1);
	cout << ans << "\n";
	return 0;
}
