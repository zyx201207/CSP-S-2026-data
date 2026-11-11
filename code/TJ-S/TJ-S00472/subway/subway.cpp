#include<bits/stdc++.h>
using namespace std;

//short dx[2] = {-1,1};
long long m,n,w[500005],k[505],a[505][500005],t[505][500005],d,q,x[100005],y[100005],c;
//long long nodeLines[505][20]; //i,j = 经过第i个地铁站的第j条线路 
//long long cntLines[505]; //i = 经过第i个地铁站的线路总数
//long long mp[505]; 
//queue<long long> que;
//
//void draw() {
//	while(!que.empty()) {
//		long long nowx = que.front();
//		que.pop();
//		for(int i = 1; i <= cntLines[nowx]; ++i) {
//			int place;
//			for(int j = 1; j <= k[nodeLines[nowx][i]]; ++j) {
//				
//			}
//			for(int j = 0; j < 2; ++j) {
//				int nx = a[nodeLines[nowx][i]][place];
//			}
//		}
//		for(int i = 0; i < 2; ++i) {
//			int nx = nowx + dx[i];
//			if(nx < 1 || nx > k[cntLines[nowx]] || mp[nowx] >= mp[nx]) continue;
//			que.push(nx);
//		}
//	}
//}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; ++i) {
		cin >> w[i];
	}
	for(int i = 1; i <= n; ++i) {
		cin >> k[i];
		for(int j = 1; j <= k[i]; ++j) {
			cin >> a[i][j] >> t[i][j];
//			nodeLines[a[i][j]][++cntLines[a[i][j]]] = i;
		}
	}
	for(int r = 1; r <= q; ++r) {
		cin >> x[r] >> y[r];
	}
//	for(int r = 1; r <= q; ++r) {
//		int ans = 0;
//		ans += w[x[r]] + w[y[r]];
//		int nowx = x[r],nowy = y[r];
//		que.push(x[r]);
//		draw();
//		
//		cout << ans;
//	}
	for(int r = 1; r <= q; ++r) {
		int ans = 0;
		ans += w[x[r]] + w[y[r]];
		bool flag = 0,flag2 = 0,flag3 = 0;
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= k[i]; ++j) {
				if(a[i][j] == x[r]) flag = 1;
				if(a[i][j] == y[r]) flag2 = 1;
				if(flag && flag2 && !flag3) {
					ans += t[i][x[r]] + t[i][y[r]];
					flag3 = 1;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}

