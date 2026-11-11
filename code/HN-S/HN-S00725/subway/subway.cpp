#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,e,w[500005],k[500005],a[505][500005],t[505][500005],x[100005],y[100005];
struct st{
	int number,time1,len;//第几个站点 从这个站的地铁口走到站厅需要的时间 有几个站点经过 
	vector<int>time2[25],line[25];//line存有哪几个地铁经过 time2存该地铁站的站厅走到第line条线的时间 
}g[500005];
bool vis[500005];
int solve(int start,int end){
	queue<int>q;
	q.push(start);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
		g[i].time1=w[i];
		g[i].number=i;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d %d",&a[i][j],&t[i][j]);
			g[a[i][j]].len++;
			g[a[i][j]].time2.push_back(t[i][j]);
			g[a[i][j]].line.push_back(i);
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%d %d",&x[i],&y[i]);
	}
	for(int i=1;i<=q;i++){
		printf("%d\n",solve(x[i],y[i]));
	}
	return 0;
}
