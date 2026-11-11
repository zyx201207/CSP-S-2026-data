#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,m,n,d,q,w[500005],k[506],t[506][500005],x[506],y[506];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];	
	}
	for(int i=1;i<=n;++i){
		cin>>k[i];	
		for(int j=1;j<=k[i];++j){
			int a;
			cin>>a;
			cin>>t[i][a];
	}
}
	//int r=1;
	//while(r++){
	//	cin>>r[x]>>r[y];
	//}
	return 0; 
}
