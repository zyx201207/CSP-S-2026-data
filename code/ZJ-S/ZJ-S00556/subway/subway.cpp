#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int c, n, m, d, q, w[511], k[511], a[511][511], t[511][511];
ll f[2011][2011];

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","W",stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(int i=1;i<=2000;i++) for(int j=1;j<=2000;j++) f[i][j] = 1e18;
	for (int i=1;i<=m;i++) {
		scanf("%d", &w[i]);
		//edge[i].push_back(Edge(n+i,w[i]));
		//edge[n+i].push_back(Edge(i,w[i]));
		f[i][m+i]=w[i];
		f[m+i][i]=w[i];
	}
	for(int i=1;i<=n;i++){
		scanf("%d", &k[i]);
		for (int j =1 ; j <= k[i]; j++) {
			scanf("%d%d", &a[i][j], &t[i][j]);
			//edge[n+j].push_back(Edge(2*n+i,t[i][j]));
			//edge[2*n+i].push_back(Edge(n+j,t[i][j]));
			f[m+a[i][j]][2*m+i]=t[i][j];
			f[2*m+i][m+a[i][j]]=t[i][j];
		}		
	}
	for(int k=1;k<=3*m;k++)
		for(int i=1;i<=3*m;i++)
			for(int j=1;j<=3*m;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for (; q--; ) {
		int x, y;
		scanf("%d%d", &x, &y);
		printf("%lld\n", f[x][y]);
	}
	return 0;	
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2*/
/*
0 3 7 20 2 
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6 
2 3

*/