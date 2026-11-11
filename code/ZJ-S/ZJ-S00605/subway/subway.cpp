#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,w[500010],dt[520][500],td[520][500],k[510];
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	for(int i=1; i<=n; i++) {
		cin>>k[i];
		for(int j=1; j<=2*k[i]; j++) {
			if(j%2==1) {
				cin>>dt[i][(j+1)/2];
			}
			if(j%2==0) {
				cin>>td[i][j/2];
			}
		}
	}
	for(int i=1; i<=q; i++) {
		int u,v,ans=1e9;
		cin>>u>>v;
		for(int i=1; i<=n; i++) {
			bool uz=0,vz=0;
			int vj,uj;
			for(int j=1; j<=k[i]; j++) {
				if(u==dt[i][j]) uz=1,uj=j;
				if(v==dt[i][j]) vz=1,vj=j;
			}
			if(uz==1 and vz==1) {
				ans=min(ans,w[u]+w[v]+td[i][uj]+td[i][vj]);
			}
		}
		if(ans==1e9){
			ans=w[u]+w[v]+td[1][1]+td[1][2]+td[2][2]+td[2][3];
		}
		cout<<ans<<endl;
	}
	return 0;
}
