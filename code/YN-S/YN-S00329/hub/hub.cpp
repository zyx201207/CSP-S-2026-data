#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int NM = 1e5 + 10, MN = 1050;
ll c, t, n, h, a, b;
bool f = 0;
ll ans = 9223372036854775806;

ll find(int x) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k[i]; j++) {

		}
	}
}

void dfs(ll y, ll x, ll sum) { //当前站台数，起始线路数
	if (y == yr) {
		ans = min(ans, sum);
		f = 1;
		return ;
	}
	for (int i = 1; i <= n; i++) { //遍历所有地铁线路
		if (i == x)
			continue;
		for (int j = 1; j <= k[i]; j++) {

		}
	}

}





//ll read(){
//	int ss=0,mm=1;
//	char cc=getchar();
//	while(cc<'0'||cc>'9'){
//		if(cc=='-'){
//			mm=-1;
//		}
//		cc=getchar();
//	}
//	while(cc>='0'&&cc<='9'){
//		ss=ss*10+(cc-'0');
//		cc=getchar();
//	}
//	return ss*mm;
//}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	for (int ttt = 1; ttt <= t; ttt++) {
		cin >> n >> k;
		while (cin >> a >> b);
		cout << ttt << endl;
	}
	return 0;
}