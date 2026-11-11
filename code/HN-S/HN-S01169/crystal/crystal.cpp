#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5e5 + 5;

int n, m, c = 1, sum, ans, a[N];
queue<int> q;

signed main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	q.push(a[1]);
	for(int i = 2; i <= n; i++){
		q.push(a[i]);
		sum += (a[i] - a[i - 1]) * c;
		c++;
		if(sum > m){
			sum -= a[i] - q.front();
			q.pop();
			c--;
		}
		ans = max(ans, c);
	}
	cout << ans;
	return 0;
}

