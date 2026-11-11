#include<bits/stdc++.h>
#define pb emplace_back
using namespace std;
const int N=1e6+10;
int n,m,dfn[N],ed[N],w[N],cnt,dep[N],fa[N][20],st[N][20],p[N],sum,ma,root=1,f[N];
inline int find(int x){
	while(x!=f[x])x=f[x]=f[f[x]];
	return x;
}
vector<int>e[N],e2[N];
inline int checkmin(int x,int y){return (dep[x]<dep[y])?x:y;}
inline void dfs(int u){
	dfn[u]=++cnt;
	w[cnt]=u;
	dep[u]=dep[fa[u][0]]+1;
	for(int v:e[u]){
	  if(v==fa[u][0])continue;
	  fa[v][0]=u;
	  dfs(v);
	}
	ed[u]=cnt;
}
inline int getk(int u,int k){
	if(k>=dep[u]-1)return root;
	while(k){
	  u=fa[u][__lg(k)];
	  k^=(1<<__lg(k));
	}
	return u;
}
inline int getlca(int l,int r){
	if(l==r)return l;
	l=dfn[l],r=dfn[r];
	if(l>r)swap(l,r);
	++l;
	int k=__lg(r-l+1);
	return checkmin(st[l][k],st[r-(1<<k)+1][k]);
}
inline int getdis(int x,int y){return dep[x]+dep[y]-(dep[getlca(x,y)]<<1);}
bitset<N>use;
inline int dfs2(int u,int fa){
	++sum;
	int ma1=0,ma2=0;
	for(int v:e2[u]){
	  int c=dfs2(v,u);
	  if(c>ma1)ma2=ma1,ma1=c;
	  else ma2=max(ma2,c);
	  sum+=dep[v]-dep[u]-1;
	}
	if(!use[u])ma=max(ma,ma1+ma2-1);
	else ma=max(ma,ma1-1);
	if(use[u])return dep[u]-dep[fa];
	else return ma+dep[u]-dep[fa];
}
inline bool check(int k){
	vector<int>vec;
	for(int i=1;i<=n;++i){
	  if((int)vec.size()>m){
		for(int x:vec)use[x]=0;
		return 0;
	  }
	  int u=p[i];
	  bool flag=0;
	  for(int x:vec){
		if(getdis(x,u)<=k){
		  flag=1;
		  break;
		}
	  }
	  if(flag)continue;
	  u=getk(u,k);
	  use[u]=1;
	  vec.pb(u);
	}
	if((int)vec.size()==1)return 1;
	vector<int>vec2=vec;
	sort(vec.begin(),vec.end(),[&](int x,int y){return dfn[x]<dfn[y];});
	for(int i=0;i+1<(int)vec.size();++i)vec2.pb(getlca(vec[i],vec[i+1]));
	swap(vec,vec2);
	sort(vec.begin(),vec.end(),[&](int x,int y){return dfn[x]<dfn[y];});
	vec.resize(unique(vec.begin(),vec.end())-vec.begin());
	for(int x:vec)e2[x].clear();
	vector<int>s;
	sum=ma=0;
	for(int x:vec){
	  while(!s.empty()&&ed[s.back()]<dfn[x])s.pop_back();
	  if(!s.empty())e2[s.back()].pb(x);
	  s.pb(x);
	}
	dfs2(s[0],0);
//	cout<<"114514\n";
//	for(int x:vec)if(use[x])cout<<x<<" ";
	for(int x:vec)use[x]=0;
//	cout<<"\n";
//	cout<<sum<<" "<<ma<<"\n";
	if(sum-ma>m)return 0;
	return 1;
}
inline void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;++i)e[i].clear(),fa[i][0]=0;
	int u,v;
	for(int i=1;i<n;++i){
	  cin>>u>>v;
	  e[u].pb(v);
	  e[v].pb(u);
	}
	cnt=0;
	dfs(1);
	for(int i=1;i<=n;++i)st[i][0]=fa[w[i]][0];
	for(int j=1;j<=__lg(n);++j)
	for(int i=1;i<=n;++i)
	  fa[i][j]=fa[fa[i][j-1]][j-1];
	for(int j=1;j<=__lg(n);++j)
	for(int i=1;i+(1<<j)-1<=n;++i)
	  st[i][j]=checkmin(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	if(n<=10){
	  int limit=1<<n,ans=n;
	  for(int s=0;s<limit;++s){
		if(__builtin_popcount(s)!=m)continue;
		for(int i=1;i<=n;++i)f[i]=i;
		for(int u=1;u<=n;++u){
		  if(!((s>>(u-1))&1))continue;
		  for(int v:e[u]){
			if(!((s>>(v-1))&1))continue;
			f[find(u)]=find(v);
		  }
		}
		int cnt=0;
		for(int i=1;i<=n;++i){
		  if(!((s>>(i-1))&1))continue;
		  cnt+=(i==find(i));
		}
		if(cnt>2)continue;
		int ma=0;
		for(int u=1;u<=n;++u){
		  if((s>>(u-1))&1)continue;
		  int mi=n;
		  for(int v=1;v<=n;++v){
			if((s>>(v-1))&1)
			  mi=min(mi,getdis(u,v));
		  }
		  ma=max(ma,mi);
		}
		ans=min(ans,ma);
	  }
	  cout<<ans<<"\n";
	  return;
	}
	for(int i=1;i<=n;++i)p[i]=i;
	sort(p+1,p+1+n,[&](int x,int y){return dep[x]>dep[y];});
	int l=0,r=n-1;
	while(l<=r){
	  int mid=(l+r)>>1;
	  if(check(mid))r=mid-1;
	  else l=mid+1;
	}
	cout<<l<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int C,T;
	cin>>C>>T;
	while(T--)solve();
	return 0;
}
/*
0 3
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8
6 5
1 2
2 5
4 5
5 3
3 6
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9


0 1
5 2
1 2
2 3
3 4
4 5

0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10


感觉是要二分答案一下，不然不太能做。

二分答案为 k。

有一个想法，每次找到这个树上当前最深的且不合法的点，把它的 k 级祖先选一下。

如果这些点的虚树大小减去虚树上的最长链长度 <= k 就合法。

这个最长链是指最长的两个被选点的距离，且中间没有其他被选点。

好像不太对，但是如果我随机一个根呢？或者说拿直径中点来当根？
*/