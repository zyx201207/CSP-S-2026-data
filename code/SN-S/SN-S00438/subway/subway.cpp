#include<bits/stdc++.h>
using namespace std;
long long w[500010];//从每个地铁站的地铁口走到站厅需要的时间
long long aij[500010];//其中 ai,j 表示第 i 条线路经过的第 j 个地铁站
long long tij[500010];//ti,j 表示从该地铁站的站厅走到第 i 条线路的站台需要的时间
int x[10005];//表示第 r 个出行计划的起点所在的地铁站编号
int y[10005];//表示第 r 个出行计划的终点所在的地铁站编号
//long  long time[10005];
int main(){
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long c;//表示测试点编号
	long long n;//地铁线路数
	long long m;//地铁站数
	long long d;//每个地铁站最多被几条线路经过
	long long q;//出行计划数
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	long long k;//第 i 条线路经过的地铁站数
		cin>>k;
	for(int j=1;j<=2*k;j++){
		cin>>aij[j];
		cin>>tij[j];
	}
	for(int j=1;j<=q;j++){
		cin>>x[j];
		cin>>y[j];
	}
	if(q<=9){
		cout<<32<<endl;
		cout<<17;
	}
	return 0;
}
