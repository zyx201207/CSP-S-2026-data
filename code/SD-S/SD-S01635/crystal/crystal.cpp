#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 5e5 + 10;

int n;
ll m, a[maxn];

int main() {
	
   	ios::sync_with_stdio(false);
 	cin.tie(0); cout.tie(0); 
 	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
 
	cin >> n >> m;
	bool flagA = false, flagB = false;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != a[i - 1] && i != 1) flagA = false;
		if ((a[i] - a[i - 1]) != (a[i - 1] - a[i - 2]) && i >= 3) flagB = false;
	}
	sort(a + 1, a + 1 + n);
	
	if (flagA) {
		cout << n << endl;
	} else if (flagB) {
		int ans = 0;
		ll delta = a[2] - a[1];
		ll cost = delta;
		while(m > 0){
			ans++;
			m = m - cost;
			cost += delta;
		}
		cout << ans << endl;
	} else {
		ll mx = 0;
		ll cost = 0, cnt = 0, lsta = 0;
		deque< pair<ll, ll> > st;
		for (int i = 1; i <= n; i++) {
			ll del = a[i] - a[i - 1]; //跃升需要的能量 
			ll cur_cnt = 1; //这次的次数 
		
			while(a[i] == a[i + 1] && i + 1 <= n) {
				i++;
				cur_cnt++;
			} //记录同一个数值的水晶 
		
			while(cost + cnt * del > m) {
				if (st.empty()) break;
				
				pair<ll, ll> cur = st.front();
				st.pop_front();
				ll id = cur.first, cntt = cur.second;
				if ((cost - (lsta - id) * cntt) + (cnt - cntt) * del < m) {
					cost = cost - (lsta - id) * cntt;
					cnt = cnt - cntt;
					ll remain = m - cost - cnt * del;
					ll xinzeng = remain/(a[i] - id);
					if (xinzeng > 0) {
						st.push_front({id, xinzeng});
						cost += xinzeng * (lsta - id);
						cnt += xinzeng;
					}
				} else {
					cost = cost - (lsta - id) * cntt;
					cnt = cnt - cntt;
				}
				mx = max(mx, cnt);
				if (st.empty()) {
					cost = cnt = 0;
					break;
				}
			}
			if (cost + cnt * del <= m) {
				cost = cost + cnt * del;
				cnt = cnt + cur_cnt;
				mx = max(mx, cnt);
				st.push_back({a[i], cur_cnt});
			} 
			lsta = a[i];
		}
		cout << mx << endl;	
	}
	
	fclose(stdin);
	fclose(stdout);
} 
