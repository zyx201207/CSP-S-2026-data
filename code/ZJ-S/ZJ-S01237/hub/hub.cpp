#include<bits/stdc++.h>
#define endl '\n';
using namespace std;
const int N=1000005,inf=1e9;
int n,k,dfn[N],lgg[N],st[22][N],tot,dep[N],ans,delu,delv,led[N],fa[N],s,t,mx[N];
vector<int> q[N],p;
pair<int,int> d[N];
void dfs1(int u,int f){
	st[0][dfn[u]=++tot]=f;dep[u]=dep[f]+1;
	for(int v:q[u]){
		if(v==f) continue;
		dfs1(v,u);
	}
}
int get(int x,int y){
	return dfn[x]<dfn[y]?x:y;
}
int lca(int x,int y){
	if(x==y) return x;
	if((x=dfn[x])>(y=dfn[y])) swap(x,y);
	int g=lgg[y-x++];
	return get(st[g][x],st[g][y-(1<<g)+1]);
}
int len(int x,int y){
	int l=lca(x,y);
	return dep[x]+dep[y]-dep[l]-dep[l];
}
pair<int,int> merge(pair<int,int> x,pair<int,int> y){
	pair<int,int> res;
	int a=x.first,b=x.second,c=y.first,d=y.second,mx=-inf,o;
	if((o=len(a,b))>mx) res={a,b},mx=o;
	if((o=len(a,c))>mx) res={a,c},mx=o;
	if((o=len(a,d))>mx) res={a,d},mx=o;
	if((o=len(b,c))>mx) res={b,c},mx=o;
	if((o=len(b,d))>mx) res={b,d},mx=o;
	if((o=len(c,d))>mx) res={c,d},mx=o;
	return res;
}
void dfs2(int u,int f){
	d[u]={u,u};
	for(int v:q[u]){
		if(v==f) continue;
		dfs2(v,u);
		d[u]=merge(d[u],d[v]);
	}
}
void dfs3(int u,int f,pair<int,int> now){
	int m=0;
	vector<int> son;
	for(int v:q[u]) if(v!=f) son.push_back(v);
	m=son.size();
	if(m==0) return;
	vector<pair<int,int> > l(m),r(m);
	l[0]=d[son[0]];
	for(int i=1;i<m;i++) l[i]=merge(l[i-1],d[son[i]]);
	r[m-1]=d[son[m-1]];
	for(int i=m-2;i>=0;i--) r[i]=merge(r[i+1],d[son[i]]);
	for(int i=0;i<m;i++){
		int v=son[i];
		pair<int,int> o=now;
		if(i>0) o=merge(o,l[i-1]);
		if(i<m-1) o=merge(o,r[i+1]);
		int le=max(len(o.first,o.second),len(d[v].first,d[v].second));
		if(le<ans){
			ans=le;
			delu=u;
			delv=v;
		}
		dfs3(v,u,merge(o,{v,v}));
	}
}
void dfs4(int u,int f,int c){
	dep[u]=dep[f]+1;fa[u]=f;led[u]=c;
	for(int v:q[u]){
		if(v==f) continue;
		dfs4(v,u,c);
	}
}
void dfs5(int u,int f){
	fa[u]=f;
	for(int v:q[u]){
		if(v==f) continue;
		dfs5(v,u);
	}
}
void dfs6(int u,int f){
	mx[u]=0;
	for(int v:q[u]){
		if(v==f) continue;
		dfs6(v,u);
		mx[u]=max(mx[u],mx[v]+1);
	}
}
bool check(int x){
	int sum=2;
	for(int i=1;i<=n;i++) if(!led[i]&&mx[i]>=x) sum++;
	int m=p.size();
	vector<int> res(m),mxl(m),mxr(m);
	for(int i=0;i<m;i++){
		int u=p[i];
		if(mx[u]>=x) res[i]=1;
	}
	mxl[0]=0;
	for(int i=1;i<m;i++){
		mxl[i]=mxl[i-1];
		if(res[i]) mxl[i]=i;
		else mxl[i]=max(mxl[i],i-(x-mx[p[i]]));
	}
	mxr[m-1]=m-1;
	for(int i=m-2;i>=0;i--){
		mxr[i]=mxr[i+1];
		if(res[i]) mxr[i]=i;
		else mxr[i]=min(mxr[i],i+(x-mx[p[i]]));
	}
	for(int i=0;i+1<m;i++){
		int o=sum+mxl[i]+m-1-mxr[i+1];
		if(o<=k) return 1;
	}
	return 0;
}
namespace solve{
	int ans,led[4005][4005],vis[4005],fa[4005],dep[4005],s,t,mx[4005],cnt[4005];
	void dfs(int u,int f,int c){
		vis[u]=c;fa[u]=f;dep[u]=dep[f]+1;
		for(int v:q[u]){
			if(v==f||!led[u][v]) continue;
			dfs(v,u,c);
		}
	}
	void dfs1(int u,int f){
		mx[u]=0;fa[u]=f;
		for(int v:q[u]){
			if(v==f||!led[u][v]) continue;
			dfs1(v,u);
			mx[u]=max(mx[u],mx[v]+1);
		}
	}
	struct node{
		int id,num;
	};
	struct cmp{
		bool operator()(node x,node y){
			return x.num<y.num;
		}
	};
	priority_queue<node,vector<node>,cmp> pq;
	void solve(){
		for(int i=1;i<=n;i++) vis[i]=0;
		dfs(1,0,1);
		s=1;
		for(int i=1;i<=n;i++) if(vis[i]==1&&dep[i]>dep[s]) s=i;
		dfs(s,0,1);
		for(int i=1;i<=n;i++) if(vis[i]==1&&dep[i]>dep[s]) s=i;
		{
			int o=dep[s];
			while(dep[s]!=(o+1)/2) s=fa[s];
		}
		for(int i=1;i<=n;i++) if(!vis[i]){
			t=i;
			break;
		}
		dfs(t,0,2);
		for(int i=1;i<=n;i++) if(vis[i]==2&&dep[i]>dep[t]) t=i;
		dfs(t,0,2);
		for(int i=1;i<=n;i++) if(vis[i]==2&&dep[i]>dep[t]) t=i;
		{
			int o=dep[t];
			while(dep[t]!=(o+1)/2) t=fa[t];
		}
		dfs1(s,0);dfs1(t,0);
		int m=k-2;
		for(int i=1;i<=n;i++) cnt[i]=0;
		for(int i=1;i<=n;i++) if(i!=s&&i!=t) cnt[mx[i]]++;
		for(int i=n;i>=0;i--){
			if(m<cnt[i]){
				ans=min(ans,i+1);
				break;
			}
			m-=cnt[i];
		}
	}
	void Solve(){
		ans=inf;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) led[i][j]=0;
		for(int i=1;i<=n;i++)
			for(int j:q[i])
				led[i][j]=1;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(led[i][j]){
					led[i][j]=led[j][i]=0;
					solve();
					led[i][j]=led[j][i]=1;
				}
			}
		}
		cout<<ans<<endl;
	}
}
void Solve(){
	cin>>n>>k;
	tot=0;
	for(int i=1;i<=n;i++) q[i].clear();
	for(int i=1;i<=n;i++) led[i]=0;
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		q[u].push_back(v);
		q[v].push_back(u);
	}
	if(n==k){
		cout<<0<<endl;
		return;
	}
	if(n<=4000){
		solve::Solve();
		return;
	}
	dfs1(1,0);
	for(int i=2;i<=n;i++) lgg[i]=lgg[i>>1]+1;
	for(int i=1;i<=lgg[n];i++)
		for(int j=1;j+(1<<i)-1<=n;j++)
			st[i][j]=get(st[i-1][j],st[i-1][j+(1<<(i-1))]);
	dfs2(1,0);
	ans=inf;
	dfs3(1,0,{1,1});
	for(int i=0;i<(int)q[delu].size();i++){
		if(q[delu][i]==delv){
			swap(q[delu][i],q[delu].back());
			q[delu].pop_back();
			break;
		}
	}
	for(int i=0;i<(int)q[delv].size();i++){
		if(q[delv][i]==delu){
			swap(q[delv][i],q[delv].back());
			q[delv].pop_back();
			break;
		}
	}
	dfs4(delu,0,1);
	s=0;
	for(int i=1;i<=n;i++)
		if(led[i]==1){
			if(!s) s=i;
			else if(dep[i]>dep[s]) s=i;
		}
	dfs4(s,0,1);
	for(int i=1;i<=n;i++)
		if(led[i]==1)
			if(dep[i]>dep[s]) s=i;
	{
		int o=dep[s];
		while(dep[s]>(o+1)/2) s=fa[s];
	}
	dfs4(delv,0,2);
	t=0;
	for(int i=1;i<=n;i++)
		if(led[i]==2){
			if(!t) t=i;
			else if(dep[i]>dep[t]) t=i;
		}
	dfs4(t,0,2);
	for(int i=1;i<=n;i++)
		if(led[i]==2)
			if(dep[i]>dep[t]) t=i;
	{
		int o=dep[t];
		while(dep[t]>(o+1)/2) t=fa[t];
	}
	q[delu].push_back(delv);
	q[delv].push_back(delu);
	dfs5(s,0);
	{
		p.clear();
		int x=t;
		while(x!=s){
			p.push_back(x);
			x=fa[x];
		}
		p.push_back(s);
		reverse(p.begin(),p.end());
	}
	for(int i=1;i<=n;i++) led[i]=0;
	for(int x:p) led[x]=1;
	for(int u:p){
		mx[u]=0;
		for(int v:q[u]){
			if(!led[v]){
				dfs6(v,u);
				mx[u]=max(mx[u],mx[v]+1);
			}
		}
	}
	int L=1,R=n;
	while(L<=R){
		int mid=(L+R)>>1;
		if(check(mid)){
			ans=mid;
			R=mid-1;
		}
		else L=mid+1;
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--) Solve();
	return 0;
}