#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const int M = 3e5 + 10;
int n, m, a[N], cnt[M], pos[M];
bool vis[M];
void sol() {
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			if(!pos[a[j]]) pos[a[j]] = j;
			else {
				for(int k = pos[a[j]]; k < j; k++) pos[a[k]] = 0;
				pos[a[j]] = j;
			}
		}
		for(int j = i; j <= n; j++) {
			if(pos[a[j]]) cnt[a[j]]++;
			pos[a[j]] = 0;
		}
	}
}
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sol();
	for(int i = 1; i <= m; i++) cout << cnt[i] << " ";
	return 0;
}
