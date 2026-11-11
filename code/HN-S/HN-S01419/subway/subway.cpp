#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505],dis[505][505];
vector<int>a[505],t[505],v[505];
struct node{
	int plc,dis;
};
vector<node>va[505];
void bfs(int x){
	bool vis[505];
	memset(vis,0,sizeof(vis));
	queue<node>q;
	q.push({x,0});
	while(!q.empty()){
		node top = q.front();
		q.pop();
		dis[x][top.plc] = top.dis;
		for(int i = 0; i < v[top.plc].size(); i ++){
			int ii = v[top.plc][i];
			for(int j = 0; j < a[ii].size(); j ++){
				int jj = a[ii][j];
				if(vis[jj])continue;
				vis[jj] = 1;
				q.push({jj,top.dis + 1});
			}
		}
	}
}
void bfsa(int x){
	bool vis[505];
	memset(vis,0,sizeof(vis));
	queue<node>q;
	q.push({x,0});
	while(!q.empty()){
		node top = q.front();
		q.pop();
		dis[x][top.plc] = top.dis;
		for(int i = 0; i < va[top.plc].size(); i ++){
			node ii = va[top.plc][i];
			if(vis[ii.plc])continue;
			vis[ii.plc] = 1;
			q.push({ii.plc,top.dis + ii.dis});
		}
	}
}
void bfss(int x){
	memset(dis,0x3f,sizeof(dis));
	queue<node>q;
	q.push({x,0});
	while(!q.empty()){
		node top = q.front();
		q.pop();
		if(dis[x][top.plc] <= top.dis)continue;
		dis[x][top.plc] = top.dis;
		for(int i = 0; i < v[top.plc].size(); i ++){
			int ii = v[top.plc][i],out;
			for(int j = 0; j < k[ii]; j ++){
				if(a[ii][j] == top.plc)out = j;
			}
			for(int j = 0; j < k[ii]; j ++){
				int jj = a[ii][j];
				q.push({jj,top.plc + t[ii][j] + t[ii][out]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1; i <= m; i ++)cin>>w[i];
	bool bb = 1,ba = 1;
	int bt;
	for(int i = 1; i <= n; i ++){
		cin>>k[i];
		if(k[i] > 2)ba = 0;
		for(int j = 1; j <= k[i]; j ++){
			int aa,tt;
			cin>>aa>>tt;
			if(bt != tt && i != 1)bb = 0;
			bt = tt;
			a[i].push_back(aa);
			t[i].push_back(tt); 
		}
	}
	if(bb){
		for(int i = 1; i <= n; i ++){
			for(int j = 0; j < k[i]; j ++){
				v[a[i][j]].push_back(i);
			}
		}
		for(int i = 1; i <= n; i ++)bfs(i);
	}else if(ba){
		for(int i = 1; i <= n; i ++){
			if(k[i] == 2){
				va[a[i][0]].push_back({a[i][1],t[i][0] + t[i][1]});
				va[a[i][1]].push_back({a[i][0],t[i][0] + t[i][1]});
			}
		}
		for(int i = 1; i <= n; i ++)bfsa(i);
	}else{
		for(int i = 1; i <= n; i ++){
			for(int j = 0; j < k[i]; j ++){
				v[a[i][j]].push_back(i);
			}
		}
		for(int i = 1; i <= n; i ++)bfss(i);
	}
	while(q --){
		int x,y;
		cin>>x>>y;
		if(bb)cout<<dis[x][y] * 2 * bt + w[x] + w[y]<<"\n";
		else if(ba)cout<<dis[x][y] + w[x] + w[y]<<"\n";
		else cout<<dis[x][y] + w[x] + w[y]<<"\n";
	}
	return 0;
}
