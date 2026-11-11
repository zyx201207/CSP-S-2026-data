#include <bits/stdc++.h>
using namespace std;
queue<int> q;
map<long long , int> map1;
long long a[2000010];
int bfs(long long l , long long r , long long d) {
	q.push(l);
	q.push(0);
	int s = 0;
	int ans = 0;
	while (!q.empty()) {
		long long x = q.front();
		q.pop();
		int cnt = q.front();
		q.pop();
		for (long long i = 1; i <= d; i++) {
			long long nl = x + i;
			if (nl > r) {
				break;
			}
			if (nl == r && s == 0) {
				s = cnt;
				++ans;
			} else if (nl == r && cnt == s){
				++ans; 
			} else if (nl != r && map1[l] == 1){
				q.push(nl);
				q.push(cnt + 1); 
			}
		} 
	}
	if (ans == 2) {
		return 1;
	} else {
		return 0;
	}
}
int main() {
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	long long c , t;
	cin >> c >> t;
	long long f;
	for (int i = 0; i < t; i++) {
		long long n , d;
		cin >> n >> d;
		
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			f = max(a[i] - a[i - 1] , f);
			map1[a[i]] = 1;
		}
		d = max(d , f);
		if (d >= a[n] - a[1]) {
			cout << 0 << endl;
			continue;
		}
		int cnt = 0;
		for (int l = 1; l < n; l++) {
			for (int r = l + 3; r <= n; r++) {
				cnt += bfs(a[l] , a[r] , d);
			}
		}
		for (int i = 1; i <= n; i++) {
			map1[a[i]] = 0;
		}
		cout << cnt << endl;
    }
	return 0;
}