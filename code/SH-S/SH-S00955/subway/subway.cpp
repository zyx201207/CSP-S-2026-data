#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn=505,maxm=15005;
int c,n,m,d,q,w[maxm],dis[maxm][maxm],f[maxm][maxm];

void add_edge(int a,int b,int T) {
	if (dis[a][b]==0) {
		dis[a][b]=T;
		return;
	}
	dis[a][b]=min(dis[a][b],T);
	return;
}

void floyd() {
	for (int k=1;k<=m;k++) {
		for (int i=1;i<=m;i++) {
			if (i==k||dis[i][k]==0) continue;
			for (int j=1;j<=m;j++) {
				if (i==j||j==k||dis[k][j]==0) continue;
				if (dis[i][j]==0) {
					dis[i][j]=dis[i][k]+dis[k][j];
				}else{
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
	}
}

int main() {
	cin.tie(0);
    cout.tie(0);
	freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i=1;i<=m;i++) {
    	cin >> w[i];
	}
	for (int i=1;i<=n;i++) {
		int k,a[maxm],t[maxm];
		cin >> k;
		for (int j=1;j<=k;j++) {
			cin >> a[j] >> t[j];
			for (int k=1;k<j;k++) {
				add_edge(a[j],a[k],t[j]+t[k]);
				add_edge(a[k],a[j],t[k]+t[j]);
				
			} 
		}
	}
	floyd();
	for (int i=1;i<=q;i++) {
		int x,y;
		cin >> x >> y;
		cout << dis[x][y]+w[x]+w[y] << endl;
	}
}
