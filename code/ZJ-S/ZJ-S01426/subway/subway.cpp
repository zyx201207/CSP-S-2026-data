#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=505,M=5e5+5;
const int int_inf=0x3f3f3f3f;
int c,n,m,d,q;
void open(string s){
	if(!s.size())return;
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
struct node{
	int v,len;
	bool type;
	bool operator>(node x)const{
		return len<x.len;
	}
};
int w[M],k[N];
int dis[2][N];
vector<node>g[2][N];
void dij(int st){
	bool vis[2][N];
	for(int i=0;i<=2;i++){
		for(int j=1;j<=N;j++)dis[i][j]=int_inf;
	}
	memset(vis,sizeof(vis),0);
	priority_queue<node,vector<node>,greater<node> >q;
	q.push({st,0,0});
	vis[0][st]=1;
	while(!q.empty()){
		node nu=q.top();
		q.pop();
		int u=nu.v,lw=nu.len;
		bool t=nu.type;
		for(node nv:g[t][u]){
			int v=nv.v,w=nv.len;
			bool nt=nv.type;
			if(vis[nt][v])continue;
			if(dis[nt][v]>dis[t][u]+w){
				dis[nt][v]=w;
				q.push({v,dis[nt][v],nt});
				vis[nt][v]=1;
			}
		}
	}
}
int main(){
	open("subway");
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a,t;
			cin>>a>>t;
			cout<<a<<' '<<t<<endl;
			g[1][i].push_back({a,t,0});
			g[0][a].push_back({i,t,1});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		dij(x);
		int ans=w[x]+w[y]+dis[0][y];
		cout<<ans<<endl;
	}
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
*/
