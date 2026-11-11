//SN-S00283 Aapwp gxyz
#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
int id,T,n,k;
struct edge{
	int to,nxt;
}e[maxn<<1];
int head[maxn],edgenum;
void add_edge(int u,int v){
	e[++edgenum].nxt=head[u];
	e[edgenum].to=v;
	head[u]=edgenum;
}

int dep[maxn],f[maxn][22];
void ppp(int x,int fa){
	dep[x]=dep[fa]+1;
	f[x][0]=fa;
	for(int i=0;i<=19;i++){
		f[x][i+1]=f[f[x][i]][i];
	}
	for(int i=head[x];i;i=e[i].nxt){
		int v=e[i].to;
		if(v==fa) continue;
		ppp(v,x);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=20;i>=0;i--){
		if(dep[f[x][i]]>=dep[y]) x=f[x][i];
		if(x==y) return x;
	}
	
	for(int i=20;i>=0;i--){
		if(dep[f[x][i]]!=dep[f[y][i]]){
			x=f[x][i],y=f[y][i];
		}
	}
	return f[x][0];
}
int dis(int x,int y){
	return dep[x]+dep[y]-2*dep[lca(x,y)];
}

int ans=2e9,p[maxn],h[maxn];
int find(int x){
	if(h[x]==x) return x;
	return h[x]=find(h[x]);
}
void merge(int x,int y){
	x=find(x),y=find(y);
	h[x]=y;
}
void dfs(int x){
	if(x==n+1){
		int cnt=0;
		for(int i=1;i<=n;i++) cnt+=p[i];
		if(cnt!=k) return;
		vector<int> q;
		for(int i=1;i<=n;i++){
			if(p[i]) q.push_back(i);
		}
		iota(h+1,h+1+n,1);
		for(auto x:q){
			for(auto y:q){
				if(dis(x,y)==1) merge(x,y);
			}
		}
		set<int> qwq;
		for(auto x:q) qwq.insert(find(x));
		if(qwq.size()!=2) return;
		
		int tot=0;
		for(int i=1;i<=n;i++){
			if(!p[i]){
				int d=2e9;
				for(auto j:q)
					d=min(d,dis(i,j));
				tot=max(tot,d);
			}
		}
		ans=min(ans,tot);
		return;
	}
	p[x]=1,dfs(x+1);
	p[x]=0,dfs(x+1);
}

void clean(){
	edgenum=0;
	for(int i=1;i<=n;i++) head[i]=0;
	ans=2e9;
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>id>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1,x,y;i<n;i++){
			cin>>x>>y;
			add_edge(x,y),add_edge(y,x);
		}
		ppp(1,0);
		dfs(1);
		cout<<ans<<'\n';
		clean();
	}
	
}
