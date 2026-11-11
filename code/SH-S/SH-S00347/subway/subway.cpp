#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k[510],x,y,w[500010],a[510][500010],t[500010][510];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=i;i<=m;++i) cin>>w[i];
	for(int i=1;i<=n;++i){
		cin>>k[i];
		for(int j=1;j<=k[i];++j) cin>>a[i][j]>>t[j][i];
	}
	for(int i=1;i<=q;++i){
		cin>>x>>y;
		int ans=0;
		cout<<ans<<endl;
	}
	return 0;
}
