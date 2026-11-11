#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y,k[505],w[500005],a[505][500005],t[505][500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j];
			cin>>t[i][j];
		}
	}while(q--){
		cin>>x>>y;
		long long ans;
		ans=w[x]+w[y];
		ans+=t[1][x];
		ans+=t[n][y];
		cout<<ans<<"\n";
	}return 0;
}