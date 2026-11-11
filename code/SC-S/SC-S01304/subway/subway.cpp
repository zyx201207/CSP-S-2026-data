#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;

struct zhan{
	int w;//地铁口走到站厅的时间
	int X[501];
	vector<int> A;//哪些线路经过这个站
};//记录每个站台的数据

vector<vector<int> > K;//表示线路i经过哪些站台
vector<zhan> M;
vector<int> vis(m+1);
int solve(int x,int y,int t,int fa){//刨开到地铁口的时间
	if(x==y){
		return t;
	}
	int ans = INT_MAX;
	vis[x] = 1;
	for(int a : M[x].A){//枚举我在这个站台可以坐哪些线路
		if(a==fa) continue;
		int kt = t + M[x].X[a];//我现在到这条线路上的时间
		for(int i : K[a]){//现在这条线路上有哪些点
			if(i==x||vis[i]){//如果这个点是自己或者是刚刚从那里来的，就不考虑
				continue;
			}
			//时间要加上从这条线路到对应站台的时间
			vis[i] = 1;
			ans = min(ans,solve(i,y,kt+M[i].X[a],a));
			vis[i] = 0;
		}
	}
	return ans;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过、出行计划数
	M.resize(m+1);
	for(int i=1,x;i<=m;i++){
		cin>>x;
		M[i].w = x;
	}
	K.resize(n+1);
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		for(int j=1,a,t;j<=x;j++){
			cin>>a>>t;
			M[a].A.push_back(i);
			M[a].X[i] = t;
			K[i].push_back(a);
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		for(int i=1;i<=m;i++) vis[i] = 0;
		cout<<solve(x,y,0,0)+M[x].w+M[y].w<<'\n';
	}
	return 0;
}