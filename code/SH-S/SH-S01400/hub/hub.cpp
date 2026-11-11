#include<bits/stdc++.h>
using namespace std;
#define gc getchar()
#define pc(x) putchar(x)
typedef long long ll;
inline ll rd(){ll x=0;char c=gc;bool f=0;while(c<48||c>57) c=='-'&&(f=-1),c=gc;while(c>47&&c<58) x=(x<<3)+(x<<1)+(c^48),c=gc;return f?-x:x;}
inline void ot(ll x){if(x<0) pc('-'),ot(-x);else if(x>9) ot(x/10),pc((x%10)^48);else pc(x^48);}
ll c,t,n,k,u,v,o,ans,pa[1000009],d[1000009],g[10009],G[10009],fa[10009],w[10009],U[10009],V[10009];
bool z[1000009],vst[10009];
vector<int> a[1000009];
queue<int> q;
multiset<int,greater<int>> p,P;
inline int find(int x){return x==pa[x]?x:pa[x]=find(pa[x]);}
inline void dfs(int x){
	vst[x]=1,g[x]=d[x],G[x]=0;
	for(int &i:a[x]) if(!vst[i]) d[i]=d[x]+1,fa[i]=x,dfs(i),g[x]=max(g[x],g[i]),G[x]=max(G[x],G[i]+1);
}
inline ll dfs2(int x){
	ll r=max(G[x],max((ll)(p.empty()?0:*p.begin()),P.empty()?0:*P.begin()+d[x]));
	multiset<int,greater<int>> F;
	for(int &i:a[x]) if(fa[i]==x) F.insert(G[i]);
	for(int &i:a[x]) if(fa[i]==x){
		F.erase(F.find(G[i])),w[d[x]]=(F.empty()?-100000000:*F.begin()+1),P.insert(w[d[x]]-d[x]);
		if(d[i]%2==0) P.erase(P.find(w[d[i]/2]-d[i]/2)),p.insert(w[d[i]/2]+d[i]/2);
		r=min(r,dfs2(i));
		if(d[i]%2==0) P.insert(w[d[i]/2]-d[i]/2),p.erase(p.find(w[d[i]/2]+d[i]/2));
		P.erase(P.find(w[d[x]]-d[x])),F.insert(G[i]);
	}
	return r;
}
int main(){
	freopen("hub.in","r",stdin),freopen("hub.out","w",stdout);
	c=rd(),t=rd();
	while(t--){
		n=rd(),k=rd(),ans=0x3f3f3f3f;
		for(int i=1;i<=n;++i) a[i].clear();
		for(int i=1;i<n;++i) u=rd(),v=rd(),a[u].push_back(v),a[v].push_back(u);
		if(k==n){pc('0'),pc('\n');continue;}
		if(c==13||c==14){ll m=n/2;ot(k>=m?1:(m-k+3)/4+1),pc('\n');continue;}
		if(c==7){
			for(int i=1;i<=n;++i){
				for(int j=0;j<=n+1;++j) vst[j]=0,U[j]=V[j]=fa[j]=d[j]=g[j]=G[j]=0;
				dfs(i);
				for(int j=0;j<a[i].size();++j) U[j+1]=max(U[j],g[a[i][j]]);
				for(int j=a[i].size()-1;~j;--j) V[j+1]=max(V[j+2],g[a[i][j]]);
				for(int j=0;j<a[i].size();++j) p.clear(),P.clear(),ans=min(ans,max(dfs2(a[i][j]),max(U[j],V[j+2])));
			}
			ot(ans),pc('\n');
			continue;
		}
		for(int _=0;_<(1<<n);++_) if(__builtin_popcount(_)==k){
			for(int i=1;i<=n;++i) d[i]=0x3f3f3f3f,z[i]=0;
			iota(pa+1,pa+n+1,1);
			for(int i=1;i<=n;++i) if(_&(1<<(i-1))){z[i]=1;for(int &j:a[i]) if(z[j]) pa[find(j)]=find(i);}
			int e=0;
			for(int i=1;i<=n;++i) if(z[i]&&pa[i]==i) ++e;
			if(e>2) continue;
			for(int i=1;i<=n;++i) if(z[i]) q.push(i),d[i]=0;
			o=0;
			while(!q.empty()){
				int f=q.front();
				q.pop(),o=max(o,d[f]);
				for(int &i:a[f]) if(d[i]==0x3f3f3f3f) d[i]=d[f]+1,q.push(i);
			}
			ans=min(ans,o);
		}
		ot(ans),pc('\n'); 
	}
	return 0;
}
