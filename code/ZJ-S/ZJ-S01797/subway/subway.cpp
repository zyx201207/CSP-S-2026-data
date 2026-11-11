#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
struct node{
	int u,to,ti;
	bool operator <(const node&o)const{
		return ti>o.ti;
	}
};
vector<node>tree[N+1005];
int c,m,n,d,q,w[N];
int dis[2005][2005],mb[2][N],minn=1e18;
void init(){
	for(int i=1;i<=m;i++){
		dis[i][i]=1e18;
	}
}
void dj(int x){
	for(int i=1;i<=m+n;i++)dis[x][i]=1e18;
	priority_queue<node>q;
	q.push({x,0,0});
	dis[x][x]=0;
	while(!q.empty()){
		int u=q.top().u;
		q.pop();
		for(int i=0;i<tree[u].size();i++){
			int v=tree[u][i].to,w=tree[u][i].ti;
			if(dis[x][v]>dis[x][u]+w){
				dis[x][v]=dis[x][u]+w;
				q.push({v,0,dis[x][v]});
			}
		}
	}
}
signed main(void){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
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
			int to,ti;
			cin>>to>>ti;
			tree[m+i].push_back({m+i,to,ti});
			tree[to].push_back({to,m+i,ti});
		}
	}
	if(m<=1500){
		init();
		while(q--){
			int x,y;
			cin>>x>>y;
			if(x>y)swap(x,y);
			
			if(dis[x][x]==0){
				cout<<dis[x][y]+w[x]+w[y]<<'\n';
			}
			else{
				dj(x);
				cout<<dis[x][y]+w[x]+w[y]<<'\n';
			}
		}
		return 0;
	}
	if(n==2){
		for(int i=0;i<2;i++)for(int j=1;j<=m;j++)mb[i][j]=1e18;
		for(int i=1;i<=n;i++){
			for(int j=0;j<tree[i+m].size();j++){
				int y=tree[i+m][j].to,w=tree[i+m][j].ti;
				mb[i-1][y]=w;
			}
		}
		for(int i=1;i<=m;i++)minn=min(minn,mb[0][i]+mb[1][i]);
		while(q--){
			int x,y;
			cin>>x>>y;
			cout<<w[x]+w[y]+min(mb[0][x]+mb[0][y],min(mb[1][x]+mb[0][y]+minn,min(mb[0][x]+mb[1][y]+minn,mb[1][x]+mb[1][y])))<<'\n';
		}
		return 0;
	}
	return 0;
}

