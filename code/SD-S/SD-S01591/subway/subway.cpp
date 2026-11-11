#include<bits/stdc++.h>
using namespace std;
const long long maxn=6e5+7,inf=1e18+7;
long long n,m,c,q,d,head[maxn],tote,dis[1010][1010],tot,W[maxn],ned[maxn],ds[maxn],vis[maxn],T,Ds[3][maxn];
map<pair<long long,long long>,long long> mp;
struct node{
	int to,nxt;
	long long w;
}e[maxn<<2];
void add(int u,int v,long long w){
	tote++;
	e[tote].to=v;
	e[tote].w=w;
	e[tote].nxt=head[u];
	head[u]=tote;
	return ;
}
priority_queue<pair<long long,long long> >que;
void dij(int s){
	while(!que.empty()){
		que.pop();
	}
	for(int i=1;i<=tot;i++){
		dis[s][i]=inf;
	}
	dis[s][s]=0;
	que.push({0,s});
	while(!que.empty()){
		long long x=que.top().second,D=que.top().first*(-1ll);
		que.pop();
		if(D!=dis[s][x]){
			continue;
		}
		for(int i=head[x];i;i=e[i].nxt){
			int y=e[i].to;
			if(dis[s][y]>D+e[i].w){
				dis[s][y]=D+e[i].w;
				que.push({-1ll*dis[s][y],y});
			}
		}
	}
	return ;
}
queue<int> q2;
void dij2(int s){
	while(!que.empty()){
		que.pop();
	}
	for(int i=1;i<=tot;i++){
		Ds[s-m][i]=inf;
	}
	Ds[s-m][s]=0;
	que.push({0,s});
	while(!que.empty()){
		long long x=que.top().second,D=que.top().first*(-1ll);
		que.pop();
		if(D!=Ds[s-m][x]){
			continue;
		}
		for(int i=head[x];i;i=e[i].nxt){
			int y=e[i].to;
			if(Ds[s-m][y]>D+e[i].w){
				Ds[s-m][y]=D+e[i].w;
				que.push({-1ll*Ds[s-m][y],y});
			}
		}
	}
	return ;
}
vector<int> st,ed[100010];
void bfs(int s){
	for(int i=1;i<=tot;i++){
		ds[i]=inf;
		vis[i]=0;
	}
	ds[s]=0;
	while(!q2.empty()){
		q2.pop();
	}
	q2.push(s);
	vis[s]=1;
	while(!q2.empty()){
		long long x=q2.front();
		q2.pop();
		//vis[x]=1;
		for(int i=head[x];i;i=e[i].nxt){
			int y=e[i].to;
			if(vis[y]){
				continue;
			}
			ds[y]=ds[x]+1;
			vis[y]=1;
			q2.push(y);
		}
	}
	for(auto i:ed[s]){
		mp[{s,i}]=ds[i]*T;
	}
	return ;
}
struct qry{
	long long x,y;
}ask[maxn];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	if(c<=11){
		for(int i=1;i<=m;i++){
			scanf("%lld",&W[i]);
		}
		tot=m;
		for(int i=1;i<=n;i++){
			tot++;
			long long cnt;
			scanf("%lld",&cnt);
			for(int j=1;j<=cnt;j++){
				long long id,D;
				scanf("%lld%lld",&id,&D);
				add(id,tot,D);
				add(tot,id,D);
			}
		}
		for(int i=1;i<=m;i++){
			dij(i);
		}
		while(q--){
			long long x,y;
			scanf("%lld%lld",&x,&y);
			cout<<min(dis[x][y],dis[y][x])+W[x]+W[y]<<'\n';
		}
		return 0;
	}
	else if(c>=12&&c<=15){
		for(int i=1;i<=m;i++){
			scanf("%lld",&W[i]);
		}
		tot=m;
		for(int i=1;i<=n;i++){
			tot++;
			long long cnt;
			scanf("%lld",&cnt);
			for(int j=1;j<=cnt;j++){
				long long id,D;
				scanf("%lld%lld",&id,&D);
				T=D;
				add(id,tot,D);
				add(tot,id,D);
			}
		}
		for(int i=1;i<=q;i++){
			long long x,y;
			scanf("%lld%lld",&x,&y);
			ask[i]={x,y};
			ned[x]=1;
			ed[x].push_back(y);
		}
		for(int i=1;i<=m;i++){
			if(ned[i]){
				st.push_back(i);
			}
		}
		for(auto i:st){
			bfs(i);
		}
		for(int i=1;i<=q;i++){
			cout<<mp[{ask[i].x,ask[i].y}]+W[ask[i].x]+W[ask[i].y]<<'\n';
		}
		return 0;
	}
	else if(20<=c&&c<=21){
		for(int i=1;i<=m;i++){
			scanf("%lld",&W[i]);
		}
		tot=m;
		for(int i=1;i<=n;i++){
			tot++;
			long long cnt;
			scanf("%lld",&cnt);
			for(int j=1;j<=cnt;j++){
				long long id,D;
				scanf("%lld%lld",&id,&D);
				add(id,tot,D);
				add(tot,id,D);
			}
		}
		dij2(m+1);
		dij2(m+2);
		while(q--){
			long long x,y;
			scanf("%lld%lld",&x,&y);
			cout<<min({Ds[1][x]+Ds[1][y],Ds[2][x]+Ds[2][y],Ds[1][x]+Ds[1][m+2]+Ds[2][y],Ds[2][x]+Ds[2][m+1]+Ds[1][y]})+W[x]+W[y]<<'\n';
		}
		return 0;
	}
	else{
		for(int i=1;i<=m;i++){
			scanf("%lld",&W[i]);
		}
		tot=m;
		for(int i=1;i<=n;i++){
			tot++;
			long long cnt;
			scanf("%lld",&cnt);
			for(int j=1;j<=cnt;j++){
				long long id,D;
				scanf("%lld%lld",&id,&D);
				T=D;
				add(id,tot,D);
				add(tot,id,D);
			}
		}
		for(int i=1;i<=q;i++){
			long long x,y;
			scanf("%lld%lld",&x,&y);
			ask[i]={x,y};
			ned[x]=1;
			ed[x].push_back(y);
		}
		for(int i=1;i<=m;i++){
			if(ned[i]){
				st.push_back(i);
			}
		}
		for(auto i:st){
			bfs(i);
		}
		for(int i=1;i<=q;i++){
			cout<<mp[{ask[i].x,ask[i].y}]+W[ask[i].x]+W[ask[i].y]<<'\n';
		}
		return 0;
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

32
17
*/
