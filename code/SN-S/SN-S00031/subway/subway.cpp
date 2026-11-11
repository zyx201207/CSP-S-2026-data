#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,n,m,d,q;//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，出行计划数
int w[N];//表示从每个地铁站的地铁口走到站厅需要的时间
int a[501][N];//表示第 i 条线路经过的第 j 个地铁站
int t[501][N];//表示从该地铁站的站厅走到第 i 条线路的站台需要的时间
int x,y;
void bfs(int po){
	
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<m;i++){
		cin>>w[i];
	}
	int xx=0;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			xx+=t[i][j]; 
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		cout<<x;
	}
	return 0;
}
