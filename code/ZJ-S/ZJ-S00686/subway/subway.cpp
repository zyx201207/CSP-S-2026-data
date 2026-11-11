#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>

using namespace std;
const int e=3e6+10;

int c,n,m,d,q;
int dis[e],w[e];
bool vis[e];
int tot;

struct node{
	int pos,w;
	bool operator < (const node &ano)const{return w<ano.w;}
	bool operator > (const node &ano)const{return w>ano.w;}
};
struct edge{
	int v,w;
};
vector<edge>mp[e];

void read_file(string topic){
	freopen((topic+".in").c_str(),"r",stdin);
	freopen((topic+".out").c_str(),"w",stdout);
	return ;
}

int f(int var,int num){
	if(var==1)//zhan kou
		return num;
	if(var==2)//zhan ting
		return m+num;
	if(var==3)//xian lu
		return m+m+m+num;
	return m+m+m+n+num;//zhan tai
}

void build(int u,int v,int w){
	mp[u].push_back({v,w});
	mp[v].push_back({u,w});
	return ;
}

int dijkstra(int st,int en){
	priority_queue<node,vector<node>,greater<node> >q;
	q.push({st,0});
	memset(dis,0x3f,sizeof(dis));
	dis[st]=0;
	memset(vis,0,sizeof(vis));
	
	while(!q.empty()){
		node var=q.top();
		q.pop();
		int u=var.pos;
		
		if(vis[u])
			continue;
		vis[u]=1;
		
		for(edge it:mp[u]){
			int v=it.v,w=it.w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({v,dis[v]});
			}
		}
	}
	return dis[en];
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	read_file("subway");

	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int v,w;
			cin>>v>>w;
			++tot;
			build(f(2,v),f(4,tot),w);
			build(f(4,tot),f(3,i),0);
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		cout<<dijkstra(f(2,u),f(2,v))+w[f(1,u)]+w[f(1,v)]<<'\n';
	}

	return 0;
}

