#include<bits/stdc++.h>
#define int long long
using namespace std;
const long long inf = 1e9+5;
int c,n,m,d,q;
int minn;
struct node{
	vector<int>line;
	map<int,int> times;
	int sum=0;
	
};//每个地铁站需要的时间
node a[10000006];//每个地铁站经过的线路
bool va[10000006];
vector<int> line[505];//线路，i条线路经过的点
queue<node> bfsq;
bool hasfind=false;
void bfs(int target,int sum){
	while(!bfsq.empty()){
		node f = bfsq.front();
		bfsq.pop();
		for(int i = 0;i<f.line.size();i++){
			for(int j=0;j<line[i].size();j++){
				if(!va[line[i][j]]){
					a[line[i][j]].sum = f.sum+a[line[i][j]].times[line[i][j]]+f.times[line[i][j]];
					if (line[i][j]==target){
						va[line[i][j]] = true;
						minn = min(minn,a[line[i][j]].sum);
						continue;
					}
					bfsq.push(a[line[i][j]]);
					
				}
			}
		}
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	//注意检查
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//输入
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		int ki;//表示第i条线路经过的地铁站数
		cin>>ki;
		for(int j=1;j<=ki;j++){
			int aij ,tij;
			cin>>aij>>tij;
			line[i].push_back(aij);
			a[aij].line.push_back(i);
			a[aij].times[i] = tij;
			//aij 表示第 i 条线路经过的第j 个地铁站
			//tij 表示从该地铁站的站厅走到第i条线路的站台需要的时间
			
		}
	}
	for(int i=1;i<=q;i++){
		int st,et;
		minn= 100000000;
		cin>>st>>et;
		bfsq.push(a[st]);
		bfs(et,0);
		cout<<minn;
		for(int i=0;i<=m;i++){
			va[i] = false;
		}
	}
	return 0; 
}
/*
c表示测试点编号
n地铁线路数
m地铁站数
d每个地铁站最多被几条线路经过
q以及出行计划数
输入的第二行包含m个正整数w1,w2,...,wm，
依次表示从每个地铁站的地铁口走到站厅需要的时间


*/