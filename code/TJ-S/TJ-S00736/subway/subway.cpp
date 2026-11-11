#include<iostream>
#include<cstdio>
using namespace std;
int w[500009];
int k;
int g[500009][23],h[500009][23];
int s[500009];
long long ju[509][509];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1; i<=m; i++) {
		scanf("%d",&w[i]);
	}
	int a,t;
	for(int i=1; i<=n; i++) {
		scanf("%d",&k);
		for(int j=1; j<=k; j++) {
			scanf("%d%d",&a,&t);
			s[a]++;
			g[a][s[a]]=i;
			h[a][s[a]]=t;
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			ju[i][j]=1e18;
		}
		ju[i][i]=0;
	}
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=s[i]; j++) {
			for(int k=j+1; k<=s[i]; k++) {
				ju[g[i][j]][g[i][k]]=min(ju[g[i][j]][g[i][k]],(long long)h[i][j]+h[i][k]);
				ju[g[i][k]][g[i][j]]=ju[g[i][j]][g[i][k]];
			}
		}
	}
	for(int k=1; k<=n; k++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				ju[i][j]=min(ju[i][j],ju[i][k]+ju[k][j]);
			}
		}
	}
	int x,y;
	long long minn;
	while(q--) {
		scanf("%d%d",&x,&y);
		minn=1e18;
		for(int i=1; i<=s[x]; i++) {
			for(int j=1; j<=s[y]; j++) {
				minn=min(minn,ju[g[x][i]][g[y][j]]+h[x][i]+h[y][j]);
			}
		}
		printf("%lld\n",minn+w[x]+w[y]);
	}
	return 0;
}
