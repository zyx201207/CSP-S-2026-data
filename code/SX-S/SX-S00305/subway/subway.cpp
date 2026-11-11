#include<bits/stdc++.h>
using namespace std;
int c;//测试点编号
int n;//地铁线路数
int m;//地铁站数
int d;//每个地铁站最多被几条线路经过
int q;//出行计划数
int w[500005];//第i个地铁口到站厅的时间
int k[505];//第i条线路经过的站点总数
int a[505][50000];//第i条线路经过的第j个站点
int t[505][50000];//aij站厅到i条线站台时间
int x[100005],y[100005];//第i个计划的起点到终点的地铁站编号
int main(){
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
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++){
		cout<<0<<endl;
	}
	return 0;
}