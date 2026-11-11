#include <bits/stdc++.h>
using namespace std;
const int N=5e2+10,M=5e5+10,Q=1e5+10;
long long c, n, m, d, q,w[M],k[N],a[M],t[M],x[Q],y[Q];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<k[i];j++){
			cin>>a[j]>>t[j];
		}
	}
	for(int i=1;i<=q;i++){
		cout<<x[i]<<y[i];
	}
	return 0;
}
