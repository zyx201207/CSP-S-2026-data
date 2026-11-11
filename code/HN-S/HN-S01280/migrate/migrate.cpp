#include <bits/stdc++.h>
#define ll long long
//#define debug(x) cout << #x << ' ' << x << '\n'; 
using namespace std;
int main() {
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	auto solve = [&]() {
		ll n, d;
		cin >> n >> d;
		vector<ll>va(n + 1);
		for (int i = 1;i <= n;i++) {
			cin >> va[i];
		}
		vector<array<ll, 2>>pre(n + 1);
		vector<ll> precnt(n + 1), backcnt(n + 1);
		for (int i = 1;i <= n;i++) {
			pre[i][1] = upper_bound(va.begin() + 1, va.end(), d + va[i]) - va.begin() - 1;
			pre[i][0] = lower_bound(va.begin() + 1, va.end(), va[i] - d) - va.begin();
			if(i + 1 <= n && va[i + 1] - va[i] > d){
				pre[i][1] = -100;
			}if(i - 1 > 0 && va[i] - va[i - 1] > d){
				pre[i][0] = -100;
			}
			if(i == n) {
				pre[i][1] = -100;
			} 
			if(i == 1){
				pre[i][0] = -100;
			}
		}
		
		for (int i = 1;i <= n;i++){
			if(pre[i][0] > 0 && pre[i][0] <= n)precnt[i] = precnt[pre[i][0]] + 1;
			else precnt[i] = 1;
//			debug( precnt[i]);
		}
		for (int i = n;i > 0;i--){
			if(pre[i][1] > 0 && pre[i][1] <= n)backcnt[i] = backcnt[pre[i][1]] + 1;
			else backcnt[i] = 1;
		}
		ll ans{};
		for (int i = 1;i <= n;i++){
			int step1 = pre[i][1];
			if(step1 <= 0 || step1 > n)continue;
			int step2 = step1 - 1;
			if(step2 <= 0 || step2 > n)continue;
			int step3 = pre[step2][1];
			if(step3 <= 0 || step3 > n)continue;
			int step4 = pre[step3][0];
			if(step4 <= 0 || step4 > n)continue;
			if(step2 != step4)continue;
			if(step1 == step2 || step2 == step3 || step3 == step1)continue;
			ans++;
		}
		cout << ans << '\n';
	};
	
	int c, T;
	cin >> c >> T;
	while(T--) {
		solve();
	}
	return 0;
} 

//10 3
//-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983

