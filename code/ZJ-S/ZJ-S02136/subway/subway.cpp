#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e5+5,N=505;
int c,n,m,d,q,idx,t;
int w[M],k[N],res[M],e[N][N],dis[N][N];
bool vis[N];
struct node{
	int s,t,id;
}ans[M];
bool cmp(node x,node y){
	return x.s<y.s;
}
struct point{
	int x,y;
	bool operator < (const point &a)const{
		return a.y<y;
	}
};
vector<point>v[M],u[N];
void dij(int s){
	priority_queue<point>p;
	memset(vis,0,sizeof(vis));
	p.push(point{s,0});
	dis[s][s]=0;
	while(!p.empty()){
		int u=p.top().x;
		p.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=1;i<=n;i++){
			if(i==u||e[i][u]==-1||vis[i])continue;
			if(dis[s][i]>dis[s][u]+e[i][u]||dis[s][i]==-1){
				dis[s][i]=dis[s][u]+e[i][u];
				p.push(point{i,dis[s][i]});
			}
		}
	}
}
void bfs(int s){
	memset(vis,0,sizeof(vis));
	dis[s][s]=0;
	queue<int>p;
	p.push(s);
//	cout<<s<<"\n\n";
	while(!p.empty()){
		int u=p.front();
//		cout<<u<<" ";
		vis[u]=1;
		p.pop();
		for(int i=1;i<=n;i++){
			if(i==u||vis[i]||e[u][i]==-1)continue;
			dis[s][i]=dis[s][u]+1;
			p.push(i);
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1,t1,t2;j<=k[i];j++){
			scanf("%lld%lld",&t1,&t2);
			t=t2;
			v[t1].push_back(point{i,t2});
//			u[j].push_back(x);
		}
	}
	memset(e,-1,sizeof(e));
	for(int i=1;i<=m;i++){
		if(!v[i].empty()){
			for(int j=0;j<v[i].size();j++){
				for(int l=j+1;l<v[i].size();l++){
					if(e[v[i][j].x][v[i][l].x]==-1||e[v[i][j].x][v[i][l].x]>v[i][l].y+v[i][j].y){
						e[v[i][j].x][v[i][l].x]=v[i][l].y+v[i][j].y;
						e[v[i][l].x][v[i][j].x]=v[i][l].y+v[i][j].y;
					}
				}
			}
		}
	}
	int st,ed;
	while(q--){
		scanf("%lld%lld",&st,&ed);
		ans[++idx].id=idx,ans[idx].s=st,ans[idx].t=ed;
	}
//	cout<<e[1][2]<<"\n\n";
	sort(ans+1,ans+idx+1,cmp);
	memset(dis,-1,sizeof(dis));
	memset(res,-1,sizeof(res));
	if(c>=12&&c<=19){
		for(int i=1;i<=n;i++){
			bfs(i);
		}
		for(int i=1;i<=idx;i++){
			for(int j=0;j<v[ans[i].s].size();j++){
				for(int l=0;l<v[ans[i].t].size();l++){
					st=v[ans[i].s][j].x,ed=v[ans[i].t][l].x;
					if(dis[st][ed]==-1)continue;
					if(res[ans[i].id]==-1||res[ans[i].id]>v[ans[i].s][j].y+v[ans[i].t][l].y+dis[st][ed]*2*t)
						res[ans[i].id]=dis[st][ed]*2*t+v[ans[i].s][j].y+v[ans[i].t][l].y;
				}
			}
			res[ans[i].id]+=w[ans[i].s]+w[ans[i].t];
		}
	}
	else{
		for(int i=1;i<=n;i++)dij(i);
		for(int i=1;i<=idx;i++){
			for(int j=0;j<v[ans[i].s].size();j++){
				for(int l=0;l<v[ans[i].t].size();l++){
					st=v[ans[i].s][j].x,ed=v[ans[i].t][l].x;
					if(dis[st][ed]==-1)continue;
					if(res[ans[i].id]==-1||res[ans[i].id]>v[ans[i].s][j].y+v[ans[i].t][l].y+dis[st][ed])
						res[ans[i].id]=dis[st][ed]+v[ans[i].s][j].y+v[ans[i].t][l].y;
				}
			}
			res[ans[i].id]+=w[ans[i].s]+w[ans[i].t];
		}
	}
//	cout<<"!!!";
	for(int i=1;i<=idx;i++)cout<<res[i]<<"\n";
	return 0;
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 1 2 1 4 1
//3 2 1 3 1 5 1
//1 3
//1 2
//fc /n subway.out subway.ans
