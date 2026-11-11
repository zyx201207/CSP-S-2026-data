#include <bits/stdc++.h>
using namespace std;
int w[100005],k[505],a[505][100005],t[505][100005],x[100005],y[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for (int i=1;i<=m;i++) cin >> w[i];
	for (int i=1;i<=n;i++){
		cin >> k[i];
		for (int j=1;j<=m;j++) cin >> a[i][j] >> t[i][j];
	}
	for (int i=1;i<=q;i++) cin >> x[i] >> y[i];
	
	if (n==1){
		for (int i=1;i<=q;i++) cout << w[x[q]]+w[y[q]] << endl;
	}
	return 0;
}
