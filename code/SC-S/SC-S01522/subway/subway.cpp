#include<bits/stdc++.h>
using namespace std;
int n,M[1000011],tt[5005][5005],k,l,o=1e9,x,y;
struct food {
	int a,tt;
} a[5006][5005];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin>>M[i];
	}
	for(int i=1; i<=m; i++)
		for(int j=1; j<=m; j++) {
			tt[i][j]=1e5+9;
			if(i==j)tt[i][j]=0;
		}
	for(int i=1; i<=n; i++) {
		int k;
		cin>>k;//我一定可以AC 
		for(int j=1; j<=k; j++) {
			cin>>a[i][j].a>>a[i][j].tt;
			for(int t=1; t<=j; t++) {
				tt[a[i][t].a][a[i][j].a]
				=min(tt[a[i][t].a][a[i][j].a],a[i][t].tt+a[i][j].tt);
				tt[a[i][j].a][a[i][t].a]
				=min(tt[a[i][j].a][a[i][t].a],a[i][j].tt+a[i][t].tt);
			}
		}
	}
	for(int i=1; i<=m; i++)for(int j=1; j<=m; j++)for(int k=1; k<=m; k++)tt[i][j]=min(tt[i][j],tt[i][k]+tt[k][j]);
	for(int i=1; i<=q; i++) {
		cin>>x>>y;
		cout<<tt[x][y]+M[x]+M[y]<<'\n';
	}
	return 0;//完结撒花 
}
