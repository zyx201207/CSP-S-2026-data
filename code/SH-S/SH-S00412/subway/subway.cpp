#include <bits/stdc++.h>
using namespace std;
long long w[500011],x[100010],y[100010];
long long a[505][500011];
long long t[505][500011];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++){
		long long k;
		cin>>k;
		for(long long j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(long long i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(long long i=1;i<=q;i++){
		cout<<"\n";
	}
	
	return 0;
}
