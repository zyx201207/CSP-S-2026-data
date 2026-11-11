#include<bits/stdc++.h>
using namespace std;

const int M=5e5+10007;
int c,n,m,d,t;
long long val[M];
long long dis[M];
int f[M];
bool vis[M];
vector<pair<int,int> > edge[M];
priority_queue<pair<long long,int> >q;
struct Tree{
	int l,r,len;
};
Tree tr_edge[M];
void dj(int s){
	q.push({0,s});
	memset(dis,127,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		for(auto dv:edge[u]){
			int v=dv.first;
			int len=dv.second;
			if(dis[v]>dis[u]+len){
				dis[v]=dis[u]+len;
				if(!vis[v]){
					q.push({-dis[v],v});
				}
				vis[v]=true;
			}
		}
	}
}

bool cmp(Tree a,Tree b){
	return a.len<b.len;
}

int get(int x){
	if(f[x]==x)return x;
	else return f[x]=get(f[x]);
}

void dfs(int x,int f){
	for(auto k:edge[x]){
		int y=k.first;
		int tim=k.second;
		if(y==f)continue;
		dis[y]=dis[x]+tim*1ll;
		dfs(y,x);
	}	
}

int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>t;
	for(int i=1;i<=m;i++){
		cin>>val[i];
	}
	if(c<=11){
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			for(int j=1;j<=k;j++){
				int v,len;
				cin>>v>>len;
				edge[m+i].push_back({v,len});
				edge[v].push_back({m+i,len});
			}
		}
		for(int i=1;i<=t;i++){	
			int du,dv;
			cin>>du>>dv;
			dj(du);
			cout<<dis[dv]+val[du]+val[dv]<<endl;
		}	
	}else{
	
		int cnt=0;
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			for(int j=1;j<=k;j++){
				int v,len;
				cin>>v>>len;
				tr_edge[++cnt]={v,m+i,len};
			}
		}
		for(int i=1;i<=n+m;i++){
			f[i]=i;
		}
		sort(tr_edge+1,tr_edge+1+cnt,cmp);
		for(int i=1;i<=cnt;i++){
			int x=get(tr_edge[i].l);
			int y=get(tr_edge[i].r);
			if(x==y)continue;
			f[y]=x;
			edge[tr_edge[i].l].push_back({tr_edge[i].r,tr_edge[i].len});
			edge[tr_edge[i].r].push_back({tr_edge[i].l,tr_edge[i].len});
		}
		dfs(1,0);
		dis[1]=0;
		for(int i=1;i<=t;i++){	
			int du,dv;
			cin>>du>>dv;
			int disc=abs(dis[du]-dis[dv]);
			cout<<disc+(val[du]+val[dv])*1ll<<endl;
		}
	}
	return 0;
}