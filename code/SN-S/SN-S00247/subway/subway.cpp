#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
/*
输入的第一行包含五个非负整数c,n,m,d,q，分别表示测试点编号、地铁线路数、
地铁站数、每个地铁站最多被几条线路经过，以及出行计划数。
输入的第二行包含m个正整数w1,w2,...,wm，依次表示从每个地铁站的地铁口走
到站厅需要的时间
输入的第i+2(1≤i≤n) 行包含1+2ki 个正整数，其中第一个正整数为ki，表
示第i条线路经过的地铁站数；接下来2ki个正整数为ai,1,ti,1,ai,2,ti,2,...,ai,ki
,ti,ki
，其
中ai,j 表示第 i 条线路经过的第j 个地铁站，ti,j 表示从该地铁站的站厅走到第i条线
路的站台需要的时间。
输入的第r+n+2(1≤r≤q) 行包含两个正整数xr,yr，分别表示第r 个出行计
划的起点和终点所在的地铁站编号。
*/ 
int w[512345],k[512],a[512][512345],t[512][512345];
pair<int,int> que[112345];
int dfs(int st,int ed,int val,int now){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			dfs(st,ed,val,a[i][j]);
		}
	}
	if(now==ed){
		return val;
	}
}
signed main(){
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
		cin>>que[i].first>>que[i].second;
		int val=w[que[i].first];
		cout<<w[que[i].second]+dfs(que[i].first,que[i].second,val,0)<<"\n";
	}
}
//迪杰斯特拉?
//shi li jia nb!
