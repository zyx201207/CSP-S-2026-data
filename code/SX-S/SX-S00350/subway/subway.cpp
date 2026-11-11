/*
卡3h未遂 前前后后换3种算法但经过推导发现错误 空悲切
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
ll c, n, m, d, q, kk, w[N], ans, k[N]; //n线路数 m站点数 k每条线路经过几个站点

struct Node {
	ll station, time, spot;
} b[110][N];

struct Edge {
	ll from, to, next;
} a[2 * N];
ll f[N], pre[2 * N];

void add(int u, int v) {
	a[++kk] = {u, v, pre[u]};
	pre[u] = kk;
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
//	cin>>c>>n>>m>>d>>q;
//	for(int i=1;i<=m;i++){
//		scanf("%lld",&w[i]);
//	}
//	for(int i=1;i<=n;i++){
//		cin>>k[i];
//		for(int j=1;j<=2*k[i];j++){
//			cin>>a[i][j].station>>a[i][j].time;
////			add(a[i][j-2].station,a[i][j].station);
//		}
//	}
//	ll x,y;
//	for(int i=1;i<=q;i++){
//		cin>>x>>y;
//		ans=0;
//		memset(f,false,sizeof(f));
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=k[i];j++){
//				if(f[a[i][j].station]!=0){
//					a[i][j].spot=f[a[i][j].station];
//					a[f[a[i][j].station]][j].spot=i;
//				}
//				f[a[i][j].station]=i;
//			}
//		}
//		ans+=w[x]+w[y];
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=k[i];j++){
//				i
//			}
//		}
//		ll sum=0,sum1=0;
//		for(int i=1;i<=n;i++){
//			rei=0,rej=0;
//			for(int j=1;j<=2;j++){
//				if(a[i][j].station==x){
//					if(j==1){
//						sum=min(a[i][j].time+a[i][2].time,sum);
//						rei=i;
//						rej=2;
//					}else{
//						sum=min(a[i][j].time+a[i][1].time,sum);
//						rei=i;
//						rej=1;
//					}
//				}
//				if(a[rei][rej].station==a[i][j].station){
//
//				}
//			}
//		}
//
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		scanf("%lld", &w[i]);
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> b[i][j].station >> b[i][j].time;
			add(b[i][j].station, b[i - 1][j].station);
			add(b[i - 1][j].station, b[i][j].station);
			b[i][j].spot = i;
		}
	}
	ll x, y;
	for (int i = 1; i <= q; i++) {
		cin >> x >> y;
//		for (int j = 1; j <= n; j++) {
//			ll to = a[j].to, from = a[j].from;
//			if (from == x) {

//			}
//		}
	}
	return 0;
}