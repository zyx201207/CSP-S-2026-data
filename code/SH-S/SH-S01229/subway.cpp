#include<bits/stdc++.h>
using namespace std;
typedef pair<unsigned long long,unsigned long long> pll;
typedef pair<int,int> pii;
vector<pll> g[550];
unsigned long long dist[550][550];
bool bj[550][550];
unsigned long long w[550000];
unsigned long long g0[550][550];
vector<pii> sta[550000];
void dijstra(int start){
	priority_queue<pll,vector<pll>,greater<pll> > q1;
	q1.push({0,start});
	dist[start][start]=0;
	while(!q1.empty()){
		pll tq1=q1.top();
		q1.pop();
		int dis=tq1.first;
		int t=tq1.second;
		if(bj[start][t]==1) continue;
		bj[start][t]=1;
		for(int i=0;i<g[t].size();i++){
			pll gi=g[t][i];
			int u=gi.first;
			int v=gi.second;
			if(dist[start][u]>dis+v){
				dist[start][u]=dis+v;
				q1.push({dis+v,u});
			}
		}
	}
}
unordered_map<unsigned long long,unsigned long long> mem;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	memset(g0,0x3f,sizeof(g0));
	memset(dist,0x3f,sizeof(dist));
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int ki;
		scanf("%d",&ki);
		for(int j=1;j<=ki;j++){
			int ai,ti;
			scanf("%d %d",&ai,&ti);
			sta[ai].push_back({i,ti});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<sta[i].size();j++){
			for(int k=0;k<sta[i].size();k++){
				if(i==k) continue;
				unsigned long long tl=0;
				g0[sta[i][j].first][sta[i][k].first]=min(g0[sta[i][j].first][sta[i][k].first],sta[i][j].second+sta[i][k].second+tl);
				g0[sta[i][k].first][sta[i][j].first]=g0[sta[i][j].first][sta[i][k].first];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(g0[i][j]==0x3f3f3f3f3f3f3f3f) continue;
			g[i].push_back({j,g0[i][j]});
			g[j].push_back({i,g0[j][i]});
		}
	}
	for(int i=1;i<=n;i++){
		dijstra(i);
	}
	for(int i=0;i<q;i++){
		int xr,yr;
		scanf("%d %d",&xr,&yr);
		unsigned long long mi=0x3f3f3f3f3f3f3f3f;
		bool flag=0;
		if(mem.find(min(xr,yr)*(m+1)+max(xr,yr))!=mem.end()){
			printf("%ld",mem[min(xr,yr)*(m+1)+max(xr,yr)]);
			printf("\n");
			continue;
		}
		for(int j=0;j<sta[xr].size();j++){
			for(int k=0;k<sta[yr].size();k++){
				unsigned long long xt=dist[sta[xr][j].first][sta[yr][k].first]+w[xr]+w[yr]+sta[xr][j].second+sta[yr][k].second;
				mi=min(mi,xt);
				if(flag==0){
					mi=xt;
				}
				flag=1;
			}
		}
		printf("%ld",mi);
		printf("\n");
		mem[min(xr,yr)*(m+1)+max(xr,yr)]=mi;
	}
	return 0;
}

