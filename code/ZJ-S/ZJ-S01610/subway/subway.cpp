#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int w[500010],k[500010];
int dis[10000010];
int vi[10000010];

struct node{
	int id,sa,to,cost;
	friend bool operator<(node p,node q){
		return p.cost>q.cost;
	}
};
map<node,bool>vis;
vector<node>v[10000010];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin >>w[i];
		
	}int tot=0;
	for(int i=1;i<=n;i++){
		cin >>k[i];
		int lsx=0;
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin >>x>>y;
			v[x].push_back({++tot,x,x+i*m,y});
			v[x+i*m].push_back({++tot,x+i*m,x,y});
			if(lsx){
				v[x+i*m].push_back({++tot,x+i*m,lsx+i*m,0});
				v[lsx+i*m].push_back({++tot,lsx+i*m,x+i*m,0});
			}lsx=x;
		}
	}
	for(int i=1;i<=q;i++){
		for(int k=0;k<m;k++){
			for(int j=0;j<=n;j++){
				dis[k+j*m]=LONG_LONG_MAX;
				vi[k+j*m]=0;
			}
		}
//		vector<int>dis(10000010,LONG_LONG_MAX/10);
//		vector<int>vi(10000010,0);
		vis.clear();
		int st,ed;
		cin >>st>>ed;
		priority_queue<node>q;
		q.push({0,0,st,0});
		dis[st]=0;
		while(!q.empty()){
			node u=q.top();
			q.pop();
			if(vi[u.id]){
				continue;
			}else vi[u.id]=1;
			for(int i=0;i<v[u.to].size();i++){
				node t=v[u.to][i];
				
				if(dis[t.to]>dis[u.to]+t.cost){
					dis[t.to]=dis[u.to]+t.cost;
				}q.push({t.id,u.to,t.to,t.cost});
			}
		}
		cout <<dis[ed]+w[st]+w[ed]<<'\n';
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
*/
