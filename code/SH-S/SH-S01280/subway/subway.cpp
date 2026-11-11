#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q;
int w[500010];
vector<pair<int,int> >g[1000010];//1-n ÊÇ 
struct Query{
	int pos,x,y;
}query[100010];
//int dis[1000010];
struct Edge{
	int u,v,w;
}edge[1000010];int tot=0;
int fa[1000010];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
signed st[21][1000010];
int dis[21][1000010];
int dep[1000010];
void dfs(int u,int f){
	st[0][u]=f;
	dep[u]=dep[f]+1;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i].first,w=g[u][i].second;
		if(v!=f){
			dis[0][v]=w;
			dfs(v,u);
		}
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	int ans=0;
	for(int i=20;i>=0;i--){
		if((1<<i)<=dep[x]-dep[y]){
			ans+=dis[i][x];
			x=st[i][x];
		}
	}
	if(x==y)return ans;
	for(int i=20;i>=0;i--){
		if(st[i][x]!=st[i][y]){
			ans=ans+dis[i][x]+dis[i][y];
			x=st[i][x],y=st[i][y];
		}
	}
	ans+=dis[0][x]+dis[0][y];
	return ans;
}
bool ed;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int num=m;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int last=0;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			if(last==0){
				num++;
				edge[++tot]={a,num,t};
				last=1;
			}else{
				num++;
				edge[++tot]={num-1,num,0};
				edge[++tot]={a,num,t};/*
				g[num-1].push_back({num,0});
				g[num].push_back({num-1,0});
				g[num].push_back({a,t});
				g[a].push_back({num,t});*/
			}
		}
	}
	for(int i=1;i<=num;i++){
		fa[i]=i;
	}
	sort(edge+1,edge+tot+1,[](Edge a,Edge b){
		return a.w<b.w;
	});
	for(int i=1;i<=tot;i++){
		int u=edge[i].u,v=edge[i].v,w=edge[i].w;
		int fu=find(u),fv=find(v);
		if(fu!=fv){
			fa[fu]=fv;
			g[u].push_back({v,w});
			g[v].push_back({u,w});
		}
	}
	dfs(1,0);
	for(int i=1;(1<<i)<=num;i++){
		for(int j=1;j<=num;j++){
			st[i][j]=st[i-1][st[i-1][j]];
			dis[i][j]=dis[i-1][j]+dis[i-1][st[i-1][j]];
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<lca(x,y)+w[x]+w[y]<<'\n';
	}
	/*
	for(int i=1;i<=q;i++){
		cin>>query[i].x>>query[i].y;
		for(int j=1;j<=num;j++){
			dis[j]=0x3f3f3f3f3f3f3f3f;
		}
		set<pair<int,int> >qu;
		qu.insert({0,query[i].x});
		dis[query[i].x]=0;
		while(!qu.empty()){
			pair<int,int> nw=(*qu.begin());
			qu.erase(qu.begin());int now=nw.second;
			//cout<<now.first<<"A"<<now.second<<'\n';
			for(int j=0;j<g[now].size();j++){
				int v=g[now][j].first,w=g[now][j].second;
				if(dis[v]>dis[now]+w){
					qu.erase({dis[v],v});
					dis[v]=dis[now]+w;
					qu.insert({dis[now]+w,v});
				}
			}
		}
		cout<<dis[query[i].y]+w[query[i].x]+w[query[i].y]<<'\n';
		//for(int j=1;j<=num;j++){
		//	cout<<dis[j]<<" ";
		//}
		//cout<<'\n';
		query[i].pos=i;
	}/*
	sort(query+1,query+q+1,[](Query a,Query b){
		return a.x<b.x;
	});*/
	
}
