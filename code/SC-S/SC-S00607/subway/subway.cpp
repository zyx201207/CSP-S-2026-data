#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;
typedef pair<int,int>pii;
const int mx=1e3+10;
int c,n,m,d,q,w[mx],a[mx],t[mx][mx],head[mx],cnt,dist[mx],zt[mx][mx];
bool f,vis[mx];
struct node{
	int d,next,it;
	bool fz;
}eg[mx];
void addedge(int u,int v,int it){
	eg[++cnt].d=v;eg[cnt].it=it;;
	eg[cnt].next=head[u];
	head[u]=cnt;
}
void djs(int st,int ed){
	priority_queue<pii,vector<pii>,greater<pii> >q;
	priority_queue<pii,vector<pii>,greater<pii> >qw;
	memset(dist,0x3f,sizeof(dist));
	dist[st]=w[st];
	q.push(make_pair(0,st));
	q.push(make_pair(0,0));
	while(!q.empty()){
		pii x=q.top(),x1=qw.top();
		q.pop();qw.pop();
		int u=x.second,itu=x1.second;
		if(u==ed){
			dist[u]+=t[itu][u];
			return;
		}
		for(int i=head[u];i;i=eg[i].next){
			int k=eg[i].it,v=eg[i].d,f=eg[i].fz,w;
			if(k!=itu && itu!=0){
				w=t[itu][u]+t[k][u];
			}
			if(dist[u]+w>dist[v]){
				dist[v]=dist[u]+w;
				q.push(make_pair(dist[v],v));
				qw.push(make_pair(dist[v],k));
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		cin>>a[1]>>t[1][a[1]];
		for(int j=2;j<=k;j++){
			cin>>a[j]>>t[j][a[j]];
			addedge(a[j-1],a[j],i);
			addedge(a[j],a[j-1],i);
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		djs(x,y);
		cout<<dist[y]+w[y]<<endl;
	}
	return 0;
} 