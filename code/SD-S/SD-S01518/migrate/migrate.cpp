#include<bits/stdc++.h>
using namespace std;
int c , t , n;
long long d;
long long x[2000005];
int dp[2000005]  , step[2000005] , q[4000005];
long long dc = 0;
int calc(int head , int rear) {
	int idx = head;
	long long tmp = 0;
	while(idx <= rear) {
		tmp = tmp + dp[q[idx]];
		if(tmp >= 3) return 3;
		if(step[q[idx]] == step[q[idx + 1]]) idx++;
		else break;
	}
	if(tmp == 1) return 1;
	if(tmp == 2) return 2;
}
int main() {
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	ios::sync_with_stdio(0);
	cin.tie(0) , cout.tie(0); 
	cin >> c >> t;
	while(t--) {
		cin >> n >> d;
		for(int i = 1 ; i <= n ; i++) {
			cin >> x[i];
		}
		long long ans = 0 , dc = 0;
		for(int i = 1 ; i <= n ; i++) {
			int head = 1 , rear = 0;
			if(n <= 5000) {
				for(int j = 1 ; j <= n ; j++) dp[i] = step[i] = 0;
				for(int j = 1 ; j <= 2 * n ; j++) q[i] = 0;
			}
			for(int j = i ; j <= n ; j++) {
				while(head <= rear && x[j] - x[q[head]] > d) {
					head++;
				}
				if(head <= rear) dp[j] = calc(head , rear);
				else if(j == i) dp[j] = 1;
				else break;
				if(dp[j] == 2) {
					ans++;
					dc += (n - j + 1);
				}
				if(head <= rear) step[j] = step[q[head]] + 1;
				else if(j == i) step[j] = 1;
				while(head <= rear && step[q[rear]] > step[j]) {
					rear--;
				}
				q[++rear] = j;
			}
			if(n > 5000) {
				cout << dc << "\n";
				break;
			}
		}
		if(n <= 5000) cout << ans << "\n";
	}
	return 0;
}
