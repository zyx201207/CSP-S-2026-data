#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
//每个地铁站的地铁口走到站厅需要的时间
long long w[500005];
//表示从该地铁站的站厅走到第i条线路的站台需要的时间
int tt[505][500005];
int a[505][450005];
long long k[505];
long long x,y;
struct bian {
	long long v,w,x;
};
vector<bian> b[500005];
struct xy {
	long long xl,x,ti;
};
long long BFS(long long be,long long e,long long qi) {
	queue<xy> q;
	q.push({qi,be,0});
	long long ans = 0x3f3f3f3f;
	while(!q.empty()) {
		xy t = q.front();
		q.pop();
		if (t.x == e) {
			ans = min(ans,t.ti);
			continue;
		}
		for (int i = 0;i < b[t.x].size();i++) {
			int v = b[t.x][i].v,xl = b[t.x][i].x,ti = b[t.x][i].w;
			if (b[t.x][i].x == t.xl) q.push({t.xl,v,t.ti});
			else q.push({xl,v,t.ti + ti + tt[xl][t.x]});
		}
		
	}
	return ans;
}
long long qi[500005];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for (long long i = 1;i <= m;i++) scanf("%lld",&w[i]);
	for (long long i = 1;i <= n;i++) {
		scanf("%lld",&k[i]);
		for (long long j = 1;j <= k[i];j++) {
			scanf("%d%d",&a[i][j],&tt[i][j]);
			if (j > 1) {
				b[a[i][j - 1]].push_back({a[i][j],tt[i][j - 1],i});
			}
			else qi[a[i][j]] = i;
		}
	}
	for (long long i = 1;i <= q;i++) {
		cin >> x >> y;
		printf("%lld\n",BFS(x,y,qi[x]) + w[x] + w[y] + 12);
	}
	return 0;
}