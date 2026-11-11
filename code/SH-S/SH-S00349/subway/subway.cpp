#include<bits/stdc++.h>
using namespace std;
const int N = 5e2+2;
const int M = 5e5+2;
const int Q = 1e5+2;
int c,n,m,d,q; // n-线路数, m-站点数, d-单个站点最多线路数, q-方案数 
long long w[M]; // w[i]-第i个站点进站时间 
struct lnsti{
	int a; // 站点编号 
	long long t; // 出站时间 
};
vector<insti> blog[N]; // blog[i]-线路i上的站点信息 
int qx[Q], qy[Q]; // qx[i]-方案i的起点, qy[i]-方案i的终点 
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	//floyd
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for (int i = 0; i < n; i++) {
		int k;
		scanf("%d",&k);
		lnsti nl = {0,0};
		while (k--) {
			scanf("%d%lld",&nl.a,&nl.t);
			blog[i].push_back(nl);
		}
	}
	for (int i = 0; i < q; i++) scanf("%d%d",&qx[i],&qy[i]);
	
	cout << "Sorry, I can't finish this task."
	
	
	return 0;
}
