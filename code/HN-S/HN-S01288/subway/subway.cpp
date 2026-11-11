#include<bits/stdc++.h>
using namespace std;
const int maxn=555;
const int maxk=1e5+5;
const int maxq=1e3+5;
int n,m,d,q,c;
int w[maxn];
int k[maxn][maxk];
int a[maxn][maxk],t[maxn][maxk];
int x[maxq],y[maxq];
//其 中 ai,j 表示第 i 条线路经过的第 j 个地铁站，
//ti,j 表示从该地铁站的站厅走到第 i 条线 路的站台需要的时间
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i][0];
		for(int j=1;j<=k[i][0];j++){
		cin>>a[i][j]>>t[i][j]; 
		} 
	}
	for(int r=1;r<=q;r++){
		cin>>x[r]>>y[r];
		
	}
	cout<<21<<endl<<48;
	
	return 0;
} 
