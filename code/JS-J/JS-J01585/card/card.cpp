#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n, m;
	long long a[N], ans[N];
	memset(ans, 0, sizeof(ans));
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	for (int i = 1; i <= n; i++){
		bool vis[N];
		memset(vis, false, sizeof(vis));
		for (int j = 1; j <= n; j++){
			if (j <= i - 1) continue;
			if (vis[a[j]])   memset(vis, false, sizeof(vis));
			vis[a[j]] = true;
		}
		for (int j = 1; j <= m; j++){
			if (vis[j]) {
				ans[j]++;
			}
		}
 	}
 	
	for (int i = 1; i <= m; i++){
		cout << ans[i] << ' ';
	}
	return 0;
}
