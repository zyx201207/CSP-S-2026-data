#include<bits/stdc++.h>
#define endl '\n'
#define int long long 
using namespace std;
int c,n,m,d,q;
int w[500005];
struct node{
	int u,w;
	bool operator>(node x)const{
		return w>x.w;
	}
};
//vector<int> line[505];
vector<node> stl[500005];
vector<node> lts[505];
int dij(int st,int ed){
	int dist[500005];
	priority_queue<node,vector<node>,greater<node> > q;
	memset(dist,0x3f,sizeof dist);
	q.push({st,0});
	dist[st]=0;
	while(!q.empty()){
		node ft=q.top();
		q.pop();
		int u=ft.u;
		int abcd=ft.w;
		if(u==ed){
			return dist[u]+w[st]+w[ed];
		}
		if(dist[u]<abcd){continue;}
		// cout<<u<<endl;
		for(int i=0;i<(int)stl[u].size();i++){
			int l=stl[u][i].u;
			for(int j=0;j<(int)lts[l].size();j++){
				if(lts[l][j].u!=u){
					int ltsu=lts[l][j].u;
					int ltsw=lts[l][j].w;
					if(dist[ltsu]>dist[u]+stl[u][i].w+ltsw){
						dist[ltsu]=dist[u]+stl[u][i].w+ltsw;
						q.push({ltsu,dist[ltsu]});
					}
				}
			}
		}
	}
	return 0;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			//line[i].push_back(a);
			lts[i].push_back({a,t});
			stl[a].push_back({i,t});
		}
	}
	for(int i=1;i<=q;i++){
		int st,ed;
		cin>>st>>ed;
		cout<<dij(st,ed)<<endl;
	}
	return 0;
}
/*0 2 5 20 2
 4 1 9 2 5
 3 1 5 2 7 4 6
 3 2 3 3 4 5 7
 1 3
 1 2
*/
/*0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
