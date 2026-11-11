/*
西安辅轮中学
韩谦益 
SN-S00365
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,d;
int x[2000010]; 
int dis[5010][5010];
int cnt[5010][5010];
void work() {
	cin>>n>>d;
	for(int i = 1;i<=n;i++) {
		cin>>x[i];
	}
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=n;j++) {
			if(abs(x[i]-x[j]) <= d) {
				dis[i][j] = 1;
			}
		}
	}
	for(int k = 1;k<=n;k++) {
		for(int i = 1;i<=n;i++) {
			for(int j = 1;j<=n;j++) {
				if(i == j || dis[i][k] == 0 || dis[k][j] == 0) {
					continue;
				}
				if(dis[i][j] == 0) {
					dis[i][j] = dis[i][k]+dis[k][j];
					continue;
				}
				if(dis[i][k]+dis[k][j] < dis[i][j]) {
					dis[i][j] = dis[i][k]+dis[k][j];
					continue;
				}
			}
		}
	}
	for(int k = 1;k<=n;k++) {
		for(int i = 1;i<=n;i++) {
			for(int j = 1;j<=n;j++) {
				if(i == j || dis[i][k] == 0 || dis[k][j] == 0 || dis[i][j] == 1) {
					continue;
				}
				if(dis[i][k]+dis[k][j] == dis[i][j]) {
					cnt[i][j]++;
				}
			}
		}
	}
	int ans = 0;
	for(int i = 1;i<=n;i++) {
		for(int j = i+1;j<=n;j++) {
			if(cnt[i][j] == 2) {
				ans++;
			}
		}
	}
	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=n;j++) {
			cnt[i][j] = 0;
			dis[i][j] = 0;
		}
	}
	cout<<ans<<"\n";
}
void work2() {
	cin>>n>>d;
	for(int i = 1;i<=n;i++) {
		cin>>x[i];
	}
	if(n == 1) {
		cout<<0<<"\n";
		return;
	}
	int cha = x[n]-x[n-1];
	int cnt = d/cha;
	if(cnt <= 1) {
		cout<<0<<"\n";
		return;
	}
	int ans = 0;
	for(int i = 1;i<=n;i++) {
		if(i+cnt*2-1 <= n) {
			ans++;
		}
	}
	cout<<ans<<"\n";
}
void work3() {
	cout<<0<<"\n";
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--) {
		if(c == 11 || c == 12) {
			work2();
			continue;
		}
		if(c == 13 || c == 14) {
			work3();
			continue;
		}
		work();
	}
	return 0;
}
