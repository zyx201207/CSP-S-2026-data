#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,x,y;
	cin >> c >> n >> m >> d >> q;
	int w[m+10],k[n+10],a[n+10][500010],t[n+10][500010],p[m+10];
	memset(p,1000000010,sizeof(p));
	for (int i=1;i<=m;i++){
		cin >> w[i];
	}
	for (int i=1;i<=n;i++){
		cin >> k[i];
		for (int j=1;j<=k[i];j++){
			cin >> a[i][j] >> t[i][j];
			p[a[i][j]]=min(p[a[i][j]],t[i][j]);
		}
	}
	for (int i=1;i<=q;i++){
		cin>> x >> y;
		long long ans=w[x]+w[y]+p[x]+p[y];
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
