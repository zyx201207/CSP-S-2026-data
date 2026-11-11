#include<bits/stdc++.h>
using namespace std;
int w[10000],a[1001][1001],t[1001][1001],x[10001],y[10001],s;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,k;
	cin>>c;//测试点编号 
	cin>>n;//地铁线路数
	cin>>m;//地铁站总数
	cin>>d;//每个地铁站最多被几条线路经过
	cin>>q;//出行计划数
	for(int i=1;i<=m;i++){
		cin>>w[i];//每个地铁站的地铁口走到站厅需要的时间
	}
	for(int i=1;i<=n;i++){
		cin>>k;//第i条线路经过的地铁站数
		for(int j=1;j<=k;j++){
			cin>>a[i][j];//第i条线路经过的第j个地铁站
			cin>>t[i][j];//从j个地铁站的站厅走到第i条线路的站台需要的时间
			s=s+t[i][j]; 
		}
	}
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];//起点和终点所在的地铁站编号
	} 
	//-----------------
	cout<<s;
}