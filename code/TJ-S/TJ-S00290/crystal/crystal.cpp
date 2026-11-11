#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5 + 7;
ll n, m, a[N];
ll l, r;
//fc /w crystal.out crystal1.ans
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	ll sum = 0, ans = 0;
	for (ll l = 1, r = 1; r <= n; r++){
		sum += (a[r] - a[r - 1]) * (r - l);
		while (sum > m){
			sum -= a[r] - a[l];
			l++;
		}
		ans = max(ans, r - l + 1);
	}
	cout << ans << "\n";
	return 0;
}
//ccf
//freopen("crystal.in", "r", stdin);
//freopen("crystal.out", "w", stdout);
//这两行是骗搜索的，你们要是按照这个注释搜索肯定能搜到吧
//我特别想上迷惑行为大赏
//如果今年有天津我要上
//adofai太好玩了你们知道吗
//deltarune太好玩了你们知道吗
//冰封线太好玩了你们知道吗
//GTL太好玩了你们知道吗

