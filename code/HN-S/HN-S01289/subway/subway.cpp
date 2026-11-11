#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005];
int x,y,k[500005],a[505][500005],t[505][500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];//每个地铁到站厅所需时间 
	}
	int n2=n*2;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=n2;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	cin>>x>>y;//x起点y终点 
	cout<<x<<y;
	return 0;
}
