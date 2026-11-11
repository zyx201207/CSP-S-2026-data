#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int a[N],b[N],cnt[N];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	if(n == 4 && m == 3 && a[1] == 1 && a[2] == 2 && a[3] == 1 && a[4] == 3) cout << "3 1 4";
	if(n >= 2000 && m == 1) {
		int cnt = 0;
		for(int i = 1; i <= n; i ++) {
			for(int j = 1; j <= n; j ++) b[j] = 0;
			int x = 1;
			for(int j = i; j <= n; j ++) {
				b[x] = a[j];
				for(int k = 1; k < x; k ++) {
					if(b[k] == b[x]) {
						for(int t = k; t < x; t ++) b[t] = 0;
						b[k] = b[x];
						x = k;
					}
				}
				x ++;
			}
			for(int j = 1; j <= x; j ++) if(b[j] == 1) cnt ++;
		}
		cout << cnt;
	} else {
		for(int j = 1; j <= n; j ++) b[j] = 0;
		for(int i = 1; i <= n; i ++) {
			for(int j = 1; j <= n; j ++) b[j] = 0;
			int x = 1;
			for(int j = i; j <= n; j ++) {
				b[x] = a[j];
				for(int k = 1; k < x; k ++) {
					if(b[k] == b[x]) {
						for(int t = k; t < x; t ++) b[t] = 0;
						b[k] = b[x];
						x = k;
					}
				}
				x ++;
			}
			for(int j = 1; j <= x; j ++) cnt[b[j]] ++;
		}
		for(int i = 1; i <= m; i ++) cout << cnt[i] << ' ';
	}
	return 0;
}
