#include<bits/stdc++.h>
#define int long long
using namespace std;
int useless,n,m,d,q;//d干啥的
int k,a[500005],t[500005];
int dis[500005],w[500005];
struct edge{
	int v,w;
}; 
map<int,int> e[500005];
struct node{
	int u,dis;
	friend bool operator <(node x,node y){
		return x.dis>y.dis;
	}
};
priority_queue<node> que;
void bfs(int u){
	dis[u]=0;
	que.push({u,dis[u]});
	while(!que.empty()){
		int tem=que.top().u;
//		cout << dis[tem] << ' ';
		que.pop();
		for(int i=1;i<=m;i++){
			if(!e[tem][i]) continue;
			int v=i,w=e[tem][i]; 
			if(dis[v]>dis[tem]+w){
				dis[v]=dis[tem]+w;
				que.push({v,dis[v]});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> useless >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> w[i];
	}
	for(int i=1;i<=n;i++){
		cin >> k;
		for(int j=1;j<=k;j++){
			cin >> a[j] >> t[j];//a[j]是站点，t是边权 
		} 
		for(int j=1;j<=k;j++){
			for(int h=j+1;h<=k;h++){//a[j]到a[h]站厅需要花费tj+th 
				if(!e[a[j]][a[h]] || e[a[j]][a[h]]>t[j]+t[h]){
					e[a[j]][a[h]]=t[j]+t[h];
					e[a[h]][a[j]]=t[j]+t[h];
				}
			}
		}
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++){
//			cout << e[i][j] << ' ';
//		}
//		cout << '\n';
//	}
	while(q--){
		int x,y;
		cin >> x >> y;
		if(x==y){
			cout << 0 << '\n';
			continue;
		}
		memset(dis,0x7f,sizeof(dis));
		bfs(x);
		cout << dis[y]+w[x]+w[y] << '\n';
	}
}
