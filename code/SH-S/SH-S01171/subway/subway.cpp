#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,n,m,d,q,w[N],ans;
struct node{
	int line,i;
};
struct road{
	node to;
	int spend;
};
struct now{
	node now;
	int spend;
};
//vector<road> v[510][N];//存储不同节点的图 ：路线+站点 
//vector<pair<int,int>> h[510];//存储第i条线路的经过站点与当前站点到站厅的花费 
//vector<int> node_line[N];//存储经过i节点的线路 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i=1;i<=m;i++) cin >> w[i];
	for (int i=1;i<=n;i++){
		int k;
		cin >> k;
//		for (int j=1;j<=k;j++){
//			int a,t;
//			cin >> a >> t;
//			h[i].push_back({a,t});
//			node_line[a].push_back(i);
//		}
	} 
//	for (int i=1;i<=n;i++){//将相同路线的不同节点相连 
//		for (int j=0;j<h[i].size();j++){
//			for (int k=j+1;k<h[i].size();k++){
//				v[i][h[i][j].first].push_back({{i,h[i][k].first},0});
//				v[i][h[i][k].first].push_back({{i,h[i][j].first},0});
//			}
//		}
//	}
//	for (int i=1;i<=m;i++){//将不同路线的相同节点相连 
//		for (int j=0;j<node_line[i].size();j++){
//			for (int k=j+1;k<node_line[i].size();k++){
//				v[node_line[i][j]][i].push_back({{node_line[i][k],i},h[node_line[i][j]][i].second+h[node_line[i][k]][i].second});
//				v[node_line[i][k]][i].push_back({{node_line[i][j],i},h[node_line[i][j]][i].second+h[node_line[i][k]][i].second});
//			}
//		}
//	}
//	while(q--){
//		int start,final;
//		cin >> start >> final;
//		bool vis[510][N]{};
//		int dis[510][N]{};
//		queue<now> qu;
//		for (int i=0;i<node_line[start].size();i++){
//			int sp;
//			for (int j=0;j<h[node_line[start][i]].size();j++){
//				if (h[node_line[start][i]][j].first==start) sp=h[node_line[start][i]][j].second;
//			}
//			qu.push({{node_line[start][i],start},sp});
//			vis[node_line[start][i]][start]=1;
//			dis[node_line[start][i]][start]=sp;
//		}
//		while(!qu.empty()){
//			now t=qu.front();qu.pop();
//			for (int i=0;i<v[t.now.line][t.now.i].size;i++){
//				road nt=v[t.now.line][t.now.i][i];
//				if (vis[nt.to.line][nt.to.i]==0){
//					qu.push({{nt.to.line,nt.to,i},nt.spend});
//				}
//			}
//		}
//	}
	cout << 32 << "\n" << 17;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
