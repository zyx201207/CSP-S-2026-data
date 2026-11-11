#include"bits/stdc++.h"
using namespace std;
int c,n,m,d,q;
int w[510];
int a[510][510];
int t[510][510];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int ki;
		cin>>ki
		for(int j=1;j<=2*ki;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<a[x][y]+t[x][y]<<"\n";
	}
	return 0;
}
