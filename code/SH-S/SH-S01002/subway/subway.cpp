#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int c,n,m,d,q;
int w[500005];
int k[505];
int dis[505][500505];
struct node{
	int v,t;
};
vector <node> ve[500505];
struct node2{
	int v,d;
};
bool operator>(node2 a,node2 b){
	return a.d>b.d;
}
void djk(int x){
	
	priority_queue<node2,vector<node2>,greater<node2>> pq;
	for(int i=0;i<ve[x+m].size();i++)pq.push({ve[x+m][i].v,ve[x+m][i].t});
	while(!pq.empty()){
		ll d=pq.top().d,v=pq.top().v;
		//cout<<d<<' '<<v<<endl;
		pq.pop();
		if(d>dis[x][v])continue;
		dis[x][v]=d;
		for(int i=0;i<ve[v].size();i++){
			int nx=ve[v][i].v,t=ve[v][i].t;
			if(dis[x][v]+t<dis[x][nx]){
				dis[x][nx]=dis[x][v]+t;
				pq.push({nx,dis[x][nx]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f3f3f3f3f,sizeof dis);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=m+1;i<=m+n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			int a,t;
			scanf("%d%d",&a,&t);
			ve[i].push_back({a,t});
			ve[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		djk(i);
	}
	while(q--){
		int x,y;
		ll ans=1e18;
		scanf("%d%d",&x,&y);
		for(int i=1;i<=n;i++)ans=min(ll(dis[i][x]+dis[i][y]),ans);
		printf("%lld\n",ans+w[x]+w[y]);
	}
	/*for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)cout<<dis[i][j]<<" ";*/
	fclose(stdin);
	fclose(stdout);
	return 0;
}
