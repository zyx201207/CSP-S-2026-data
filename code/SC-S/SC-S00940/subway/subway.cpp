#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y,o;
int w[500005],k[505],a[505][50005],t[505][50005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++) cin>>w[i];
	for (int i=1;i<=n;i++){
		cin>>k[i];
		for (int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for (int i=1;i<=q;i++){
		cin>>x>>y;
		cout << w[x]+w[y]+t[1][1]+t[1][1]<<"\n";
	}
	return 0;
}