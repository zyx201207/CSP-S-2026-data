#include <bits/stdc++.h>
using namespace std;
const int N=505;
const int M=5e5+5;
int c,n,m,d,q,x,y,cnt,ans;
int w[M],k[N],fa[N];
vector<int> a[N],t[N];
struct edge{
	int u,v,w;
};
vector<edge> e[N],v[M],g;
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int find(int x){
	return fa[x]==x ? x : fa[x]=find(fa[x]);
}
void merge(int x,int y,int w){
	int fx=find(x),fy=find(y);
	if(fx!=fy){
		cnt++;
		fa[fy]=fx;
		e[x].push_back({x,y,w});
		e[y].push_back({y,x,w});
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){     //建站线边，做准备 
			cin>>x>>y;
			a[i].push_back(x);
			t[i].push_back(y);
			v[x].push_back({x,i,y});  //站点所包含线路 
		}
	}
	for(int i=1;i<=m;i++){            //收集成线线边，最小生成树 
		for(int j=0;j<v[i].size();j++){
			for(int p=j+1;p<v[i].size();p++){
				g.push_back({v[i][j].v,v[i][p].v,v[i][j].w+v[i][p].w});
			}
		}
	}
	sort(g.begin(),g.end(),cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=0;i<g.size();i++){      //建线路边，通过站点连接 
		merge(g[i].u,g[i].v,g[i].w);
		if(cnt==n-1) break;
	}
	while(q--){
		cin>>x>>y;
		ans=w[x]+w[y];
		cout<<ans<<'\n';
	}
	
	
	return 0;
}