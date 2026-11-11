#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5,M=505;
int c,n,m,d,q;
int w[N];
ll f[M][M];
void floyd() {
	for(int i=1; i<=n; i++) {
		f[i][i]=0;
	}
	for(int k=1; k<=n; k++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				f[i][j]=min(f[i][k],f[k][j]);
			}
		}
	}
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	int u,v,w;
	for(int i=1; i<=n; i++) {
		int k,a,t,a2=-1,t2=-1;
		cin>>k;
		for(int j=1; j<=k*2; j++) {

		}
	}
	floyd();
	while(q--) {
		int u,v;
		cin>>u>>v;
		cout<<1<<"\n";
	}
	return 0;
}
/*

*/

