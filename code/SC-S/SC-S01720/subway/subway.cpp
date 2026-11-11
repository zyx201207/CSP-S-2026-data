#include<bits/stdc++.h>
using namespace std;
constexpr int maxm=5e5+7,maxn=507;
int c,n,m,d,que,w[maxm],k[maxn],in[maxm],dis[maxm];
vector<int>a[maxn],t[maxn];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
inline void get_pairval(int &x,int &y,pair<int,int>pp){x=pp.first,y=pp.second;}
bitset<maxm>vis;
vector<pair<int,int> >line[maxm];
int bfs(int x,int y){
	for(int i=1;i<=m;++i)dis[i]=017777777777;
	while(!q.empty())q.pop();q.push({w[x]+w[y],x}),dis[x]=w[x]+w[y];
	while(!q.empty()){
//		const auto[dist,u]=q.top();//[Warning] structured bindings only available with '-std=c++17' or '-std=gnu++17'
		int dist,u;get_pairval(dist,u,q.top());q.pop();
		if(dis[u]<dist)continue;
		for(auto _:line[u]){
//		for(auto[i,id]:line[u]){//[Warning] structured bindings only available with '-std=c++17' or '-std=gnu++17'
			int i,id;get_pairval(i,id,_);
//			cout<<i<<"=i  k[i]="<<k[i]<<'\n';
			for(int j=1;j<=k[i];++j){
				const int&v=a[i][j];
//				cout<<"    i="<<i<<" j="<<j<<" a[i][j](v)="<<v<<" in[v]="<<in[v]<<
//				"    dist[v]="<<dis[v]<<" newdist="<<dist+t[i][id]+t[i][j]<<'\n';
				if(dis[v]>dist+t[i][id]+t[i][j]){
					dis[v]=dist+t[i][id]+t[i][j];
					if(in[v]>1)q.push({dis[v],v});
				}
				
			}
			
		}
	}return(dis[y]);
}signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	 freopen("subway.in","r",stdin);
	 freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>que;
	for(int i=1;i<=m;++i)
		cin>>w[i];
	for(int i=1;i<=n;++i){
		cin>>k[i];a[i].resize(k[i]+1),t[i].resize(k[i]+1);
		for(int j=1;j<=k[i];++j)
			cin>>a[i][j]>>t[i][j],++in[a[i][j]],line[a[i][j]].emplace_back(i,j);
	}//	for(int i=1;i<=m;++i){
//		cout<<"\n"<<i<<": \n";
//		for(auto[u,v]:line[i]) cout<<u<<' '<<v<<'\n';
//		cout<<"-----\n";}
	for(int x,y;que--;){
		cin>>x>>y;
		cout<<bfs(x,y)<<'\n';
	}return(0);
}/*
#include<bits/stdc++.h>
using namespace std;
constexpr int maxm=5e5+7,maxn=507,maxq=1e5+7;
int c,n,m,d,quest,w[maxm],k[maxn],in[maxm],dis[maxm],ans[maxq];
vector<int>a[maxn],t[maxn];bitset<maxm>vis;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
inline void get_pairval(int &x,int &y,pair<int,int>pp){x=pp.first,y=pp.second;}
vector<pair<int,int> >line[maxm];pair<pair<int,int>,int >inp[maxq<<1];
priority_queue<pair<int,int> >que;
void bfs(int x){
for(int i=1;i<=m;++i)dis[i]=017777777777;
while(!q.empty())q.pop();q.push({w[x],x}),dis[x]=w[x];
while(!q.empty()){
//		const auto[dist,u]=q.top();//[Warning] structured bindings only available with '-std=c++17' or '-std=gnu++17'
int dist,u;get_pairval(dist,u,q.top());q.pop();
if(dis[u]<dist)continue;
for(auto _:line[u]){
//		for(auto[i,id]:line[u]){//[Warning] structured bindings only available with '-std=c++17' or '-std=gnu++17'
int i,id;get_pairval(i,id,_);
//			cout<<i<<"=i  k[i]="<<k[i]<<'\n';
for(int j=1;j<=k[i];++j){
const int&v=a[i][j];
//				cout<<"    i="<<i<<" j="<<j<<" a[i][j](v)="<<v<<" in[v]="<<in[v]<<
//				"    dist[v]="<<dis[v]<<" newdist="<<dist+t[i][id]+t[i][j]<<'\n';
if(dis[v]>dist+t[i][id]+t[i][j]){
dis[v]=dist+t[i][id]+t[i][j];
if(in[v]>1)q.push({dis[v],v});
}
}

}
}return;
}signed main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
//	 freopen("subway.in","r",stdin);
//	 freopen("subway.out","w",stdout);
cin>>c>>n>>m>>d>>quest;
for(int i=1;i<=m;++i)
cin>>w[i];
for(int i=1;i<=n;++i){
cin>>k[i];a[i].resize(k[i]+1),t[i].resize(k[i]+1);
for(int j=1;j<=k[i];++j)
cin>>a[i][j]>>t[i][j],++in[a[i][j]],line[a[i][j]].emplace_back(i,j);
}//	for(int i=1;i<=m;++i){
//		cout<<"\n"<<i<<": \n";
//		for(auto[u,v]:line[i]) cout<<u<<' '<<v<<'\n';
//		cout<<"-----\n";}
for(int i=1,x,y;i<=quest;++i)
cin>>x>>y,inp[i]={{x,y},i},inp[i+quest]={{y,x},i};
sort(inp+1,inp+(quest<<1)+1);
for(int i=1,j=1;i<=int(quest<<1);++i){
cout<<inp[i].first.first<<' '<<inp[i].first.second<<' '<<inp[i].second<<'\n';
if(inp[i].first.first!=inp[i-1].first.first&&i!=1)
que.push({i-j,j}),j=i;
if(i==quest<<1)que.push({i-j+1,j});
}
for(;!que.empty();){
int u,v;get_pairval(v,u,que.top()),que.pop();int temp=u;
while(inp[temp].first.first==inp[u].first.first&&ans[inp[temp].second]&&temp<=quest<<1)++temp;
if(inp[temp].first.first!=inp[u].first.first)continue;
cout<<temp<<' '<<u<<'\n';
bfs(u);
for(int i=u;v--;++i)
ans[inp[i].second]=dis[inp[i].first.second]+w[inp[i].first.second];
}for(int i=1;i<=quest;++i)cout<<ans[i]<<'\n';
return(0);
}
*/