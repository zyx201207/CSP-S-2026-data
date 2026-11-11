#include<bits/stdc++.h>
typedef long long ll;
typedef std::pair<int,int> pii;
using std::cin;
using std::cout;
constexpr int N=1e6+9;
int c,T,n,k,u[N],v[N],rt,rt_ng,pu,pv,rt_u,rt_v,center_u,center_v,t,d[N],h[N],p[N][20];
class Tree{
	public:
		struct Edge{int to,nxt;}e[N<<1];
		int hd[N],nE;
		inline void addedge(const int u,const int v){
			e[++nE]={v,hd[u]};
			hd[u]=nE;
		}
		void dfs(int u,int fa){
			d[u]=d[fa]+1;h[u]=0;
			p[u][0]=fa;
			for(int i=1;i<20;i++)p[u][i]=p[p[u][i-1]][i-1];
			for(int i=hd[u],v;i;i=e[i].nxt){
				v=e[i].to;
				if(v==fa)continue;
				dfs(v,u);
				h[u]=std::max(h[u],h[v]);
			}
			++h[u];
		}
}tree,tree_a;
int find_fa(int u,int k){
	if(!k)return u;
	for(int i=19;~i;i--){
		if(k&(1<<i))u=p[u][i];
	}
	return u;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>T;while(T--){
		cin>>n>>k;
		tree.nE=tree_a.nE=0;
		for(int i=1;i<=n;i++)tree.hd[i]=tree_a.hd[i]=0;
		for(int i=1;i<n;i++){
			cin>>u[i]>>v[i];
			tree.addedge(u[i],v[i]),tree.addedge(v[i],u[i]);
		}
		if(n==k){
			cout<<"0\n";
			continue;
		}
		tree.dfs(n>>1,0);
		rt=std::max_element(d+1,d+1+n)-d;
		tree.dfs(rt,0);
		rt_ng=std::max_element(d+1,d+1+n)-d;
		pv=find_fa(rt_ng,(d[rt_ng]>>1)-1);
		pu=p[pv][0];
		for(int i=1;i<n;i++){
			if(!(u[i]==pu&&v[i]==pv||u[i]==pv&&v[i]==pu))
				tree_a.addedge(u[i],v[i]),tree_a.addedge(v[i],u[i]);
		}
		for(int i=1;i<=n;i++)d[i]=0;
		tree_a.dfs(pu,0);
		rt_u=std::max_element(d+1,d+1+n)-d;
		tree_a.dfs(rt_u,0);
		t=std::max_element(d+1,d+1+n)-d;
		center_u=find_fa(t,d[t]>>1);
		for(int i=1;i<=n;i++)d[i]=0;
		tree_a.dfs(pv,0);
		rt_v=std::max_element(d+1,d+1+n)-d;
		tree_a.dfs(rt_v,0);
		t=std::max_element(d+1,d+1+n)-d;
		center_v=find_fa(t,d[t]>>1);
		std::sort(h+1,h+1+n);
		cout<<h[n-k]-1<<'\n';
	}
	return 0;
}

// not sure... want 100pts... should 40pts...