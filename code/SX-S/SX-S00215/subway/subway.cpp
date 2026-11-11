#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=1e6+5;
struct node{
	int x,s;
	bool operator<(const node& x)const{return s>x.s;}
};
struct ste{
	int v,w,nxt;
}edg[M];
int c,n,m,d,qe,w[N],k,u[M],v[M],t,hed[N],x,y,ans[N];
priority_queue<node> q;
void add(int u,int v,int w){
	edg[++t].v=v;
	edg[t].w=w;
	edg[t].nxt=hed[u];
	hed[u]=t;
}
int dij(int x,int y){
	memset(ans,0x3f,sizeof(ans));
	ans[x]=0;
	q.push({x,0});
	while(!q.empty()){
		node f=q.top();
		q.pop();
		for(int i=hed[f.x];i;i=edg[i].nxt){
			int nx=edg[i].v,ns=f.s+edg[i].w;
			if(ns<ans[nx]){
				ans[nx]=ns;
				q.push({nx,ns});
			}
		}
	}
	return ans[y]+w[x]+w[y];
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>qe;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=m;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>u[j]>>v[j];
			for(int l=1;l<j;l++){
				add(u[j],u[l],v[j]+v[l]);
				add(u[l],u[j],v[j]+v[l]);
			}
		}
	}
	while(qe--){
		cin>>x>>y;
		cout<<dij(x,y)<<"\n";
	}
	return 0;
}