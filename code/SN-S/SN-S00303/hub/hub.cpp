#include<bit/stdc++.h>
using namespace std;
namespace SGT{
	#define lc u<<1
	#define rc u<<1|1
	struct node{
		int l,r,sum,lazy;
	}tr[N>>1];
	void pushup(int u){
		tr[u].sum=tr[lc].sum+tr[rc].sum;
	}
	void pushdown(int u){
		if(tr[u].lazy){
			tr[lc].sum+=tr[u].lazy*(tr[lc].r-tr[lc].l+1);
			tr[rc].sum+=tr[u].lazy*(tr[rc].r-tr[rc].l+1);
			tr[lc].lazy+=tr[u].lazy;tr[rc].lazy+=tr[u].lazy;
			tr[u].lazy=0;
		}
	}
	void build(int u,int l,int r){
		tr[u]={l,r,0,0};
		if(l==r){
			tr[u].sum=w[l];
			return 0;
		}
		int mid=(l+r)>>1;
		build(lc,l,mid);
		bulid(rc,mid+1,r);
		pushup(u);
	}
	void update(int u,int x,int y,int k){
		if(x<=tr[u].l&&tr[u].r<=y){
			tr[u].sum+=k*(tr[u].r-tr[u].l+1);
			tr[u].lazy+=k;
			return 0;
		}
		pushdown(u);
		int mid=(tr[u].l+tr[u].r)>>1;
		if(l<=mid) update(lc,x,y,k);
		if(r>mid) update(rc,x,y,k);
		pushup(u);
	}
	int query(int u,int x,int y){
		if(x<=tr[u].l&&tr[u].r<=y) return tr[u].sum;
		pushdown(u);
		int mid=(tr[u].l+tr[u].r)>>1,ans=0;
		if(l<=mid) ans+=query(lc,x,y);
		if(r>mid) ans+=query(rc,x,y);
		return ans;
	}
}
int dijkstra(){
	int dis[N],vis[N];
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
	for(int i=1;i<=n;i++) dis[i]=INT_MAX;
	pq.push(0,st);
	dis[st]=0;
	while(pq.size()){
		int u=pq.top().second;
		pq.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].first;
			int w=g[u][i].second;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				pq.push({dis[v],v});
			}
		}
	}
}
int kmp(){
	int pi[N];
	for(int i=1;i<s.size();i++){
		int j=pi[i-1];
		while(j>0&&s[i]==s[j]) j=pi[j-1];
		if(s[i]==s[j]) j++;
		pi[i]=j;
	}
}
struct node{
	int count;
	vector<int> pa;
	dsu(int x){
		pa.resize(x);
		pq.iota(pa.begin(),pa.end(),0);
		count=0;
	}
	int find(int x){
		if(pa[x]==x) return x;
		else return pa[x]=find(x);
	}
	void merge(int x,int y){
		x=find(x),y=find(y);
		if(x==y) return;
		pa[y]=x;
		count--;
	}
	bool pd(int x,int y){
		return find(x)==find(y);
	}
};

int main(){
	ios::sync_wtish_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	
	
	return 0;
}
