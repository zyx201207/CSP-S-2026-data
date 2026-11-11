#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int c,n,m,d,q,w[N],a[N],t[N],cnt,head[N],dy[N],vis[N];
struct node{
	int to,nxt,w;
}e[N*400];
void add(int u,int v,int w){
	e[++cnt].nxt=head[u];
	e[cnt].to=v;
	e[cnt].w=w;
	head[u]=cnt;
}
struct nod{
	int d,u;
	bool operator <(const nod& other) const{
		return d>other.d;
	}
};
priority_queue<nod> qe;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	} 
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		cin>>a[1]>>t[1];
		for(int j=2;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		for(int x=1;x<=k;x++){
			for(int y=1;y<=k;y++){
				if(x!=y){
					add(a[x],a[y],t[x]+t[y]);
					add(a[y],a[x],t[x]+t[y]);
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		memset(dy,0x3f3f3f,sizeof dy);
		memset(vis,0,sizeof vis);
		nod p;
		p.d=0;
		p.u=x;	
		dy[x]=0;
		qe.push(p);
		while(!qe.empty()){
			nod now;
			now=qe.top();
			qe.pop();
			if(vis[now.u]){
				continue;
			}
			vis[now.u]=1;
			for(int i=head[now.u];i;i=e[i].nxt){
				int v=e[i].to;
				if(dy[now.u]+e[i].w<dy[v]){
					dy[v]=dy[now.u]+e[i].w;
					nod nww;
					nww.u=v;
					nww.d=dy[v];
					qe.push(nww);
				}
			}
		}
		cout<<w[x]+w[y]+dy[y]<<'\n';
	}
	return 0;
}

