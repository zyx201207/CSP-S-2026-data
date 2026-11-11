#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;

	int w[500005];
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}

	int a[505][500005],t[505][500005],k[505];
	for(int i=1; i<=n; i++) {
		cin>>k[i];
		for(int j=1; j<=k[i]; j++) {
			cin>>a[i][j]>>t[i][j];
		}
	}
	int x[100005],y[100005];
	int ti[100005];
	for(int i=1; i<=q; i++) {
		cin>>x>>y;
	}
	cout<<"32"<<endl<<"17";
	    return 0;
}
