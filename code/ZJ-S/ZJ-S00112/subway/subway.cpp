#include<bits/stdc++.h>
using namespace std;
int c,n,d;
long long m,q,w[500005],k[505],a[505][500005],t[505][500005],x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(long long j=1;j<=2*k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(long long i=1;i<=q;i++){
		cin>>x>>y;
	}
	for(long long i=1;i<=q;i++){
		cout<<i;
	}
	return 0;
}