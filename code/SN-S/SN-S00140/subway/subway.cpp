#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,v[500005],z[505][505],k[505];
vector<long long>a[500005],t[500005];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1; i<=m; i++)scanf("%d",&v[i]);
	for(int i=1; i<=n; i++) {
		scanf("%d",&k[i]);
		for(int j=1; j<=k[i]; j++) {
			int x,y;
			scanf("%d %d",&x,&y);
			a[x].push_back(i);
			t[x].push_back(y);
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			z[i][j]=1e18;
			if(i==j)z[i][j]=0;
		}
	}
	for(int i=1; i<=m; i++) {
		for(int j=0; j<a[i].size(); j++) {
			for(int l=0; l<=j; l++) {
				z[a[i][j]][a[i][l]]=min(z[a[i][j]][a[i][l]],t[i][j]+t[i][l]);
				z[a[i][l]][a[i][j]]=z[a[i][j]][a[i][l]];
			}
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<i; j++) {
			for(int l=1; l<=n; l++) {
				z[i][j]=min(z[i][j],z[i][l]+z[j][l]);
				z[j][i]=z[i][j];
			}
		}
	}
//	for(int i=1; i<=n; i++) {
//		for(int j=1; j<=n; j++) {
//			cout<<z[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int i=1; i<=q; i++) {
		int x,y;
		scanf("%d %d",&x,&y);
		long long ans=1e18;
		for(int j=0; j<a[x].size(); j++) {
			for(int l=0; l<a[y].size(); l++) {
				ans=min(ans,z[a[x][j]][a[y][l]]+t[x][j]+t[y][l]);
			}
		}
		cout<<ans+v[x]+v[y]<<"\n";
	}
}
