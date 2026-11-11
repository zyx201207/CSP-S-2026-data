#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
long long x[N];
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, T;
	cin >> c >> T;
	while(T--) {
		int ans = 0;
		int n, d;
		cin >> n >> d;
		for(int i = 1; i <= n; i++) cin >> x[i];
		for(int stt = 1; stt < n - 2; stt++) {
			for(int ed = stt + 3; ed <= n; ed++) {
				bool vis[N] ={};
				int cnt = 0;
				int st = stt;
				while(st < ed) {
					vis[st] = true;
					cnt++;
					long long now = x[st];
					int tof = now + d;
					for(int i = st + 1; i <= ed; i++) {
						if(x[i] > tof) {
							st = i - 1;
							break;
						} else if(x[i] <= tof && i == ed) {
							st = ed;
							break;
						}
					}
				}
				//cout << cnt << ' ';
				int cnt2 = 0;
				st = stt;
				bool flag = false;
				while(st < ed) {
					cnt2++;
					long long now = x[st];
					int tof = now + d;
					for(int i = st + 1; i <= ed; i++) {
						if(x[i] > tof) {
							if(cnt2 == 1) st = i - 2;
							else st = i - 1;
							break;
						} else if(x[i] <= tof && i == ed) {
							st = ed;
							break;
						}
					}
					if(vis[st]) {
						cnt2 = -1;
						ans++;
						break;
					}
					if(x[stt] + d < x[stt + 2]) {
						cnt2 = -1;
						break;
					}
				}
				if(cnt == cnt2) ans++;
			}
		}
		cout << ans << endl;
	}

	return 0;
}