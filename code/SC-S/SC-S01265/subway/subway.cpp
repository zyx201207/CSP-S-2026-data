#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<fstream>
using namespace std;
int main(int argc,char**argv){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	unsigned int c=0,n=500,m=5e5,d=20,q=1e5;
	cin>>c>>n>>m>>d>>q;//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过、出行计划数
	unsigned int w[m+1];//从每个地铁站的地铁口走到站厅需要的时间
	struct node{
		unsigned int to,w;
	};
	vector<node> Point[n+1];
	for(unsigned int i=1;i<=m;i++)
		cin>>w[i];
	for(unsigned int i=1;i<=n;i++){
		unsigned int k;
		cin>>k;
		while(k--){
			unsigned int a,t=1e9;
			cin>>a>>t;
			Point[i].push_back({a,t});
		}
	}
	while(q--){
		unsigned int x,y;
		cin>>x>>y;
		unsigned int dis[m+1];
		memset(dis,0x3f,sizeof dis);
		dis[x]=0;
		unsigned int now=x;
		while(now!=y){
			for(unsigned int i=0;i<Point[now].size();i++){
				i=0;
			}
		}
		cout<<dis[y];
	}
}