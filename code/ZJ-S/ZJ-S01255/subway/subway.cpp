#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k[505],a[505][505],t[505][505],b[1005][1005],f[1005][1005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		} 
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		long long u,v;
		cin>>u>>v;
		long long ans=w[u]+w[v];
		cout<<ans<<endl;
	}
	return 0;
}



