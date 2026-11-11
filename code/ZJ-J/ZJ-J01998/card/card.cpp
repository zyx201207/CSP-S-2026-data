#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+5;
const int M = 3e5+5;

int n, m;

int num[N];
int links[N];
int bottle[M];
bool vis[N];
bool ans[M];
int cnt[M];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> num[i];
		links[i] = bottle[num[i]];
		bottle[num[i]] = i;
	}
	for(int i = 1; i <= n; i++) {
		memset(ans,0,sizeof(ans));
		for(int j = i; j <= n; j++) {
			if(links[j] >= i && ans[num[j]]) {
				for(int k = links[j]; k < j; k++) {
					ans[num[k]] = 0;
				}
			}
			ans[num[j]] = 1;
		}
		for(int j = 1; j <= m; j++) {
			cnt[j] += ans[j];
		}
	}
	for(int i = 1; i <= m; i++) {
		cout << cnt[i];
		if(i == m) cout << endl;
		else cout << " ";
	}
	return 0;
}