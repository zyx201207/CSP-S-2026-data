#include<bits/stdc++.h>
#define PII pair<int,int>
#define INF 1e9+7
typedef long long int ll;
using namespace std;
const int maxn=5e5+520;
int c,n,m,d,Q,w[maxn],fir[maxn],cnt=1,dis[520][maxn];
ll ans;
bool vis[maxn];
struct node{
	int to,w,nxt;
}e[maxn*20*2+10];
void add_edge(int a,int b,int c){
	cnt++;
	e[cnt].to=b;
	e[cnt].w=c;
	e[cnt].nxt=fir[a];
	fir[a]=cnt;
}
void add(int a,int b,int c){
	add_edge(a,b,c);
	add_edge(b,a,c);
}
priority_queue<PII,vector<PII>,greater<PII> >q;
void dij(int s){
	for(int i=1;i<=m+n;i++)dis[s][i]=INF,vis[i]=0;
	dis[s][s+m]=0;
	q.push(make_pair(0,s+m));
	while(q.size()){
		int x=q.top().second;
		q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=fir[x];i;i=e[i].nxt){
			int y=e[i].to;
			if(!vis[y]&&dis[s][y]>dis[s][x]+e[i].w){
				dis[s][y]=dis[s][x]+e[i].w;
				q.push(make_pair(dis[s][y],y));
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,x,y;j<=k;j++){
			cin>>x>>y;
			add(x,m+i,y);
		}
	}
//	cout<<n<<"\n";
	for(int i=1;i<=n;i++){
		dij(i);
//		cout<<"i-th : "<<i<<"\n"; 
	}
	while(Q--){
		int x,y;
		cin>>x>>y;
		ans=INF*2;
		for(int i=1;i<=n;i++)ans=min(ans,1ll*dis[i][x]+1ll*dis[i][y]);
		cout<<w[x]+w[y]+ans<<"\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

3:08 这什么史，跳了 
4:20 赛程近似过半我又滚回来了。
地铁站到站厅的代价是只计算始末，地铁站的转移无代价，只有换乘有代价 
站厅到站台的代价可以把该地铁站挂在这条线路上，同一线路上点的转移代价是 t[x,i]+t[x,j]， 将同一线路上点进行连边，考虑最短路 
无向图，双向边
Q：q次询问，跑q次最短路真的不会炸吗？ q是1e5的小常数诶 QwQ... 
建边似乎是\sum k^2 的……
注意到d没有用上，不知道拿来优化什么（ 
不对我可以建虚拟站点把线路上的站连起来 
车站1~m，线路m+i 
4:43 样例1通过 
4:47 上厕所回来，测样例2通过 
4:56 大样例3通过(#4~#6)，大样例4正确但TLE 6s(#9~#11) 
想想d有什么用...
5:15 大样例4通过，大样例5正确但TLE 2s(#12~#15) 
5:20 哦哦d是为限制建图边数的 最多m*d条边，启发做法正确 
不是longlong卡我空间。。 
为啥不过编啊啊啊啊啊 
算了这样吧。

*/
