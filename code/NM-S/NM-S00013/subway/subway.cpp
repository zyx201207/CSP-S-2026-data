#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,x,y;
int w[500005],a[505][2],dis[50005],vis[50005];
struct V{
	int to,w;
};
vector <V> v[100005];
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch == '-') w=-1;
		ch=getchar();
	}
	while(ch>='0' && ch <='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*w;
}
void dij(int a,int b){
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
	fill(dis,dis+50002,1e9);
	fill(vis,vis+50002,0);
	dis[a]=0;
	q.push({0,a});
	while(!q.empty()){
		int c=q.top().second;
		q.pop();
		if(vis[c])continue;
		vis[c]=1;
		for(int j=0;j<v[c].size();j++){
			int u=v[c][j].to;
			if(dis[v[c][j].to]>dis[c]+v[c][j].w){
				dis[v[c][j].to]=dis[c]+v[c][j].w;
				q.push({dis[v[c][j].to],v[c][j].to});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
		v[i].push_back({2*m+i,w[i]});
		v[2*m+i].push_back({i,w[i]});
	}
	for(int i=1;i<=n;i++){
		k=read();
		for(int j=1;j<=k;j++){
			a[i][0]=read(),a[i][1]=read();
			v[a[i][0]+m].push_back({a[i][0]+m*2,a[i][1]});
			v[a[i][0]+m*2].push_back({a[i][0]+m,a[i][1]});
			v[a[i][0]].push_back({a[i-1][0],0});
			v[a[i-1][0]].push_back({a[i][0],0});
		}
	}
	for(int i=1;i<=q;i++){
		x=read(),y=read();
		dij(x,y);
		cout << dis[y] << endl;
	}
	return 0;
}
