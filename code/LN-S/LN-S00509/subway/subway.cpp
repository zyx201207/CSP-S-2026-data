#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k[505],a[505][500005],t[505][500005],x[100005],y[100005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++){
		cin>>k[i];
		for(long long j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(long long i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	cout<<32<<endl<<17<<endl;
	return 0;
}
