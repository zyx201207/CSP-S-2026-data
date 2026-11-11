#include<bits/stdc++.h>
using namespace std;
struct node{
	int id,val;
}a[550][20010];
vector<node>g[20010];
int c,n,m,d,q,w[550],k[550];
/*void solve(int x,int y){
	int vis[20050]={0},minn=INT_MAX,dis[20550],k;
	memset(dis,0x3f,sizeof(dis));
	vis[x]=1;
	for(int i=0;i<g[x].size();i++){
		vis[g[x][i].id]=1;
		dis[g[x][i].id]=g[x][i].val;
		if(minn>dis[g[x][i].id]){
			minn=dis[g[x][i].id];
			k=g[x][i].id;
		}
		if(g[x][i].id==y){
			cout<<dis[g[x][i].id]<<'\n';
			return;
		}
	}
	while(1){
		if(k==y){
			cout<<dis[k]<<'\n';
			return;
		}
		minn=INT_MAX;
		for(int i=0;i<g[x].size();i++){
			int v=g[x][i].id;
			
		}
	}
}*/
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j].id>>a[i][j].val;
		}
		/*if(k==2){
			g[a[i][1].id].push_back({a[i][2].id,a[i][1].val+a[i][2].val});
		}*/
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]<<endl;
	}
	return 0;
} 

/*
只做性质A
扣1复活昔涟（111111111 
不不不4.7看到只有耳机的我无疑是绷不住的
无心的策划，我向你发问，倘若4.7不与翁星有关，那么费半天劲对的11.12日还有什么意义
 不，还没有结束！！！我相信星际和平播报还有4.8有转机
所以接下来我要开始许愿了：
4.8昔涟sp提前备好的大保底提前出+5.0中再次以0氪玩家之躯抽取6+1
为此，我情愿跳过5.0大版本全部角色qwq 
*/
