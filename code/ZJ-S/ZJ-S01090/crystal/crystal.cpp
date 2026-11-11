#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n,m;
	cin >> n >> m;
	vector<ll> a(n);
	for (int i = 0;i < n;++i){
		cin >> a[i];
	}
	sort(a.begin(),a.end());
	ll ans = 0,cnt = 0;
	ull sum = 0;
	queue<ll> q;
	for (int i = 0;i < n;++i){
		if (i > 0){
			sum += (ull)cnt*(a[i]-a[i-1]);
		}
		++cnt;
		q.push(i);
		while (!q.empty() && sum > m){
			--cnt;
			sum -= (a[i]-a[q.front()]);
			q.pop();
		}
		ans = max(ans,cnt);
	}
	cout << ans << '\n';
	return 0;
}
/*

5 5
1 2 4 8 9

3


5 8
-3 -1 2 2 7

4
*/
