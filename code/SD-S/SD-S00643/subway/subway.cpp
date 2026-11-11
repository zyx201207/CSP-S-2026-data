#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k[505],w[500005],a[505][500005],t[505][500005],x,y,ans=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		cin>>x>>y;
		cout<<w[x]+w[y]+t[x][y];
	}
	return 0;
} 
