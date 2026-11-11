#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 10;

int n, m;
ll a[N];
ll sum[N];
ll ans = 0;

void dfs(int now, int cnt, ll sumw) {
	if(cnt == m) {
		ans = max(ans, sumw);
		return ;
	}
	
	if(now == n + 1) {
		return ;
	}
	
	dfs(now + 1, cnt + 1, (sumw & a[now]));
	dfs(now + 1, cnt, sumw);
		
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>n>>m;
	for(int i = 1; i <= n; i++) {
		cin>>a[i];
	}
	
	if(m == 1) {
		ll mx = 0;
		for(int i = 1; i <= n; i++) {
			mx = max(mx, a[i]);
		}
		
		cout<<mx;
	}else if(m == 2) {
		ll mx = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = i + 1; j <= n; j++) {
				mx = max(mx, a[i] & a[j]);
			}
		}
		
		cout<<mx;
	}else if(m == n) {
		ll mx = a[1];
		for(int i = 2; i <= n; i++) {
			mx &= a[i];
		}
		
		cout<<mx;
	}else if(n <= 20) {
		for(int i = 1; i <= n; i++) {
			dfs(i + 1, 1, a[i]);
		}
	
		cout<<ans;
	}else {
		sort(a + 1, a + 1 + n);
		cout<<a[n - m + 1];
	}

	return 0;
}
