#include<bits/stdc++.h>
using namespace std;
int c,n,d,q,m,w[500005],k,a[505][500005],t[505][500005],x,y;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		cin>>x>>y;
		cout<<w[x]+w[y]+t[x][1]+t[y][1]<<"\n";
	}
	return 0;	
}
