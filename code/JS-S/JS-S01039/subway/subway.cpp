#include<bits/stdc++.h>
using namespace std;
struct node{
	int v,id;
};
struct noode{
	int u;
	long long time;
	int id;
};
vector<node> e[500001];
long long t[501][50001],rem[501][50001];
int c,n,m,d,q,w[500003],k[500003];
bool vis[50001];
long long minn;
void bfs(int start,int end,int f){
	queue<noode>q;
	q.push({start,t[f][start]+w[start],f});
	//~ cout<<t[f][start]<<endl;
	while(!q.empty()){
		noode u=q.front();
		//~ cout<<u.u<<endl;
		q.pop();
		vis[u.u]=0;
		if(u.u==end){
			minn=min(minn,u.time+t[u.id][u.u]+w[u.u]);
		}
		for(int i=0;i<e[u.u].size();++i){
			//~ cout<<i<<" ";
			if(u.id!=e[u.u][i].id){
				//~ if(rem[e[u.u][i].id][e[u.u][i].v]<=u.time+t[u.id][u.u]+t[e[u.u][i].id][u.u]){
					//~ continue;
				//~ }
				if(vis[e[u.u][i].v]==1){
					continue;
				}
					noode tmp={e[u.u][i].v,u.time+t[u.id][u.u]+t[e[u.u][i].id][u.u],e[u.u][i].id};
					//~ rem[e[u.u][i].id][e[u.u][i].v]=u.time+t[u.id][u.u]+t[e[u.u][i].id][u.u];
					//~ cout<<e[u.u][i].id<<" "<<e[u.u][i].v<<" "<<rem[e[u.u][i].id][e[u.u][i].v]<<" "<<u.time<<endl;
					q.push(tmp);
					vis[e[u.u][i].v]=1;
			}
			else {
				//~ if(rem[e[u.u][i].id][e[u.u][i].v]<=u.time){
					//~ continue;
				//~ }
				if(vis[e[u.u][i].v]==1){
					continue;
				}
					q.push({e[u.u][i].v,u.time,u.id});
					//~ rem[e[u.u][i].id][e[u.u][i].v]=u.time;
					//~ cout<<e[u.u][i].id<<" "<<e[u.u][i].v<<" "<<rem[e[u.u][i].id][e[u.u][i].v]<<" "<<u.time<<endl;
					vis[e[u.u][i].v]=1;
			}
		}
			//~ cout<<endl;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	for(int i=1;i<=n;++i){
		cin>>k[i];
		int s,f,h;
		cin>>s>>h;
		t[i][s]=h;
		for(int j=2;j<=k[i];++j){
			cin>>f>>h;
			t[i][f]=h;
			e[s].push_back({f,i});
			//~ e[f].push_back({s,i});
			s=f;
		}
	}
	//~ cout<<endl;
	//~ for(int i=1;i<=2;++i){
		//~ for(int j=1;j<=5;++j){
			//~ cout<<t[i][j]<<" ";
		//~ }
	//~ }
	while(q--){
		int x,y;
		cin>>x>>y;
		//~ if(y>x){
			//~ int f=y;
			//~ y=x;
			//~ x=f;
		//~ }
		minn=8e18;
		for(int i=1;i<=n;++i){
			//~ memset(rem,0x7f,sizeof(rem));
			memset(vis,0,sizeof(vis));
			bfs(x,y,i);
		}
		cout<<minn<<endl;
	}
	return 0;
}
