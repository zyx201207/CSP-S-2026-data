#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500001], ans[500001], far[500001];
bool vis[500001], dist[500001];
signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		memset(vis, false, sizeof(vis));
		memset(dist, false, sizeof(dist));
		memset(far, 0, sizeof(far));
		for(int j = i;j <= n;j++){
			if(!vis[a[j]]){
				vis[a[j]] = true;
			}
			else{
				for(int k = far[a[j]];k < j;k++){
					dist[a[k]] = false;
				}
			}
			dist[a[j]] = true;
			far[a[j]] = j;
		}
		for(int j = i;j <= n;j++){
			if(dist[a[j]]){
				ans[a[j]]++;
			}
		}
	}
	for(int i = 1;i <= m;i++){
		if(i != 1){
			cout << " ";
		}
		cout << ans[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}