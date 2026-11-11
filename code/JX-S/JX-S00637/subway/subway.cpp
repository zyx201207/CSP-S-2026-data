#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int ds[500005],k[505],t[505][505],a[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>ds[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<ds[x]+ds[y]+t[1][x]+t[1][y]<<endl;
	}
	
	return 0;
}
