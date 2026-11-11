#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define endl '\n'
using namespace std;
const int N=505,M=1e5+5,X=1e3+3;
struct node{
	int dis,u,flag;
	bool operator>(const node &c)const{
		return dis>c.dis;
	}
};
vector<pii> e[M];//{v,flag}
int c,n,m,d,q,w[N],k[N],di[X][X],t[X][X];//t_i_u：第i条线站厅与地铁站u之间的距离 
vector<int> a[N],h[M];//a:站{厅}，h:厅{站} 
void dijkstra(int s){
	for (int i=1;i<=m;i++) di[s][i]=1e18;
	di[s][s]=0;
	priority_queue<node,vector<node>,greater<node>> pq;
	for (int i:h[s]) pq.push({t[i][s],s,i});
	while(!pq.empty()){
		node x=pq.top();
		int dis=x.dis,u=x.u,flagx=x.flag;
		pq.pop();
		if (di[s][u]+t[flagx][u]<dis) continue;
		for (pii y:e[u]){
			int v=y.first,flagy=y.second;
			int exd=t[flagy][v]+t[flagy][u];
			if (di[s][v]>di[s][u]+exd){
				di[s][v]=di[s][u]+exd;
				pq.push({di[s][v],v,flagy});
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i=1;i<=m;i++) cin >> w[i];
	for (int i=1;i<=n;i++){
		cin >> k[i];
		for (int j=1;j<=k[i];j++){
			int u,v;
			cin >> u >> v;
			t[i][u]=v;
			a[i].push_back(u);
			h[u].push_back(i);
		}
		for (int j=0;j<k[i];j++){
			for (int p=j+1;p<k[i];p++){
				int u=a[i][j],v=a[i][p];
				e[u].push_back({v,i});
				e[v].push_back({u,i});
			}
		}
	}
	for (int i=1;i<=m;i++) dijkstra(i);
	while(q--){
		int x,y;
		cin >> x >> y;
		cout << w[x]+di[x][y]+w[y] <<endl;
	}
	return 0;
} 
/*
14:45 开T2 
14:54 依旧图论题，预计用时 1h，看看能不能在 16:00 之前做完这题 
15:21 看错题了（）实际上好像并没有那么简单，另外这个 w 是何意味 
15:24 感觉没有什么比较好的做法，只能先建分层图了 
15:53 写了依托代码 
16:01 发现输入写错了 
16:13 通过样例1，真是绕了好大一圈啊... 
16:15 通过下发样例 1-4，期望得分 44pts 
*/ 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
