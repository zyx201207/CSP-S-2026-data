//齐君豪 西安市含光中学 SN-J00750
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200010;

int n, m;
int a[N];
int vis[N][35];
int b[N];
ll ans;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]), b[i] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 30; j >= 0; j--)
				vis[i][j] = ((a[i] >> j) & 1);
	for(int i = 30; i >= 0; i--) {
		int cnt = 0;
		for(int j = 1; j <= n; j++) {
			if(!b[j]) continue;
			if(vis[j][i] == 1)
				cnt++;
		}
		if(cnt >= m) {
			ans += (1LL << i);
			for(int j = 1; j <= n; j++)
				if(!vis[j][i])
					b[j] = 0;
		}
	}
	printf("%lld\n", ans);
	return 0;
} 
