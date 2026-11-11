#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5, M = 3e5 + 5;
int n, m, a[N], p[N][25], fl[N];
int cnt[M];

void init(){
	int vis[N];
	memset(vis, 0, sizeof(vis));
	for(int i = 1;i <= n;i++){
		if(vis[a[i]] != 0) p[vis[a[i]]][0] = i;
		vis[a[i]] = i;
	}
	for(int i = 1;i <= n;i++) if(p[i][0] == 0) fl[i] = 1;
	for(int j = 1;j <= 20;j++){
		for(int i = 1;i <= n;i++){
			if(p[i][j - 1] == 0) continue;
			p[i][j] = p[p[i][j - 1]][j - 1];
		}
	}
}

signed main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	init();
//	for(int i = 1;i <= n;i++){
//		for(int j = 0;j <= 20;j++) cout << p[i][j] << ' ';
//		cout << endl;
//	}
	for(int i = 1;i <= n;i++){
		int pp = i;
		while(pp <= n){
//			cout << pp << ' ';
			cnt[a[pp]]++;
			if(!fl[pp]){
				for(int j = 20;j >= 0;j--){
					if(p[pp][j]){
						pp = p[pp][j];
					}
				}
			}
			pp++;
		}
//		cout << endl;
//		cout << endl;
	}
	for(int i = 1;i <= m;i++) cout << cnt[i] << ' ';
	return 0;
}
