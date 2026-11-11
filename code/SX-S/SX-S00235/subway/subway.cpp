#include <bits/stdc++.h>
using namespace std;
int TestCaseID,n,m,d,q,w[500005];
vector<pair<int,int> > arr[500005];
long long dis[505][505];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &TestCaseID, &n, &m, &d, &q);
	for (int i = 1;i <= m;i++) scanf("%d", &w[i]);
	for (int i = 1;i <= n;i++){
		int k;scanf("%d", &k);
		for (int j = 1;j <= k;j++){
			int x,y;scanf("%d%d", &x, &y);
			arr[x].push_back(make_pair(i,y));
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for (int i = 1;i <= n;i++)
		dis[i][i] = 0;
	for (int i = 1;i <= m;i++){
		int l = arr[i].size();
		for (int j = 0;j < l;j++)
			for (int k = 0;k < l;k++)
				if (j != k)
					dis[arr[i][j].first][arr[i][k].first] = min(dis[arr[i][j].first][arr[i][k].first],0LL + arr[i][j].second + arr[i][k].second);
	}
	for (int k = 1;k <= n;k++)
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
	while (q--){
		int x,y;
		scanf("%d%d", &x, &y);
		long long ans = LLONG_MAX;
		for (pair<int,int> e1 : arr[x])
			for (pair<int,int> e2 : arr[y])
				ans = min(ans,w[x] + w[y] + dis[e1.first][e2.first] + e1.second + e2.second);
		printf("%lld\n", ans);
	}
	return 0;
}
