#include <bits/stdc++.h>
#include <assert.h>
#include <limits.h>
#define int long long
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pb push_back 
#define fi first
#define se second
#define pct(x) __builtin_popcount(x)
#define ctz(x) __builtin_ctz(x)
#define lowbit(x) ((x)&-(x))
#define dbg(x)
using namespace std;
constexpr int N=1000010,base=389,mod=998244353;
constexpr ll INF=0x3f3f3f3f3f3f3f3f;

template<class T> inline void ckmin(T &x,T y){x=(x<y)?x:y;}
template<class T> inline void ckmax(T &x,T y){x=(x>y)?x:y;}

namespace Zhchz{
	int C,T;
	int n,K;
	vector<int> edge[N];
	
	namespace GET50PTS{
		int lst[4010],dep[4010],sz[4010];
		int bfs(int st){
			queue<int> q;dep[st]=0;lst[st]=0;q.push(st);
			int mxdp=0,mxv=st;
			while(!q.empty()){
				int u=q.front();q.pop();
				if(dep[u]>mxdp){
					mxdp=dep[u];
					mxv=u;
				}
				for(int v:edge[u]){
					if(v==lst[u]) continue;
					dep[v]=dep[u]+1;
					lst[v]=u;
					q.push(v);
				}
			}
			return mxv;
		}
		int dfn[4010],dfr[4010],tot=0;
		void dfs1(int x,int fa){
			dep[x]=dep[fa]+1;
			sz[x]=1;
			for(int y:edge[x])
				if(y!=fa) dfs1(y,x),sz[x]+=sz[y];
		}
		int f[4010][4010];
		void dfs(int x,int fa){
			dfn[x]=++tot;
			if(fa && edge[x].size()==1){
				f[x][0]=0;
				f[x][1]=0;
				dfr[x]=tot;
				return;
			}
			
			int pre=1;
			f[x][0]=0;
			f[x][1]=0;
			for(int y:edge[x]){
				if(y==fa) continue;
				dfs(y,x);
				ckmax(f[x][0],f[y][0]+1);
				for(int i=min(pre+sz[y],K);i>=1;i--){
					int t=INF;
					for(int j=0;j<=i && j<=min(sz[y],K);j++){
						ckmin(t,max(f[x][i-j],f[y][j]+(j==0)));
					}
					f[x][i]=t;
				}
				pre+=sz[y];
			}
			
			dfr[x]=tot;
		}
		int t[16010];
		void build(int x,int l,int r){
			if(l==r){t[x]=dep[dfn[l]];return;}
			int mid=(l+r)>>1;
			build(x<<1,l,mid);build(x<<1|1,mid+1,r);
			t[x]=max(t[x<<1],t[x<<1|1]);
		}
		int query(int x,int l,int r,int from,int to){
			if(from<=l && r<=to) return t[x];
			int res=0,mid=(l+r)>>1;
			if(from<=mid) ckmax(res,query(x<<1,l,mid,from,to));
			if(to>mid) ckmax(res,query(x<<1|1,mid+1,r,from,to));
			return res;
		}
		int belong[4010];
		int solve(){
			tot=0;
			int u=bfs(1);
			int v=bfs(u);
			int len=dep[v];
			int mid=v;
			for(int i=1;i<=len/2;i++) mid=lst[mid];
			dfs1(mid,0);build(1,1,n);
			for(int i=1;i<=n;i++) for(int j=0;j<=sz[i];j++) f[i][j]=INF;
			dfs(mid,0);
			int ans=INF;
			multiset<int,greater<int>> st;
			for(int y:edge[mid]){
				for(int i=dfn[y];i<=dfr[y];i++)
					belong[i]=y;
				st.insert(f[y][0]);
			}
			for(int i=1;i<=n;i++){
				if(sz[i]<K) continue;
				pii p1={dfn[i],dfr[i]};
				int t1=belong[p1.fi];
				if(i!=mid)
					st.erase(st.find(f[t1][0]));
				
				int cur=0;
				int t=f[i][K];
				ckmax(cur,t);
				ckmax(cur,dep[i]-1);
				if(st.size()) ckmax(cur,*st.begin());
				if(i!=mid){
					if(p1.fi>1) ckmax(cur,query(1,1,n,1,p1.fi-1));
					if(p1.se<n) ckmax(cur,query(1,1,n,p1.se+1,n));
				}
				ckmin(ans,cur);
				
				if(i!=mid)
					st.insert(f[t1][0]);
			}
			for(int i=1;i<=n;i++){
				if(i==mid) continue;
				for(int j=i+1;j<=n;j++){
					if(j==mid) continue;
					if(sz[i]+sz[j]<K) continue;
					pii p1={dfn[i],dfr[i]};
					pii p2={dfn[j],dfr[j]};
					if(p1.fi>p2.fi) swap(p1,p2);
					if(p1.se>=p2.fi) continue;
					int t1=belong[p1.fi],t2=belong[p2.fi];
					st.erase(st.find(f[t1][0]));
					if(t2!=t1) st.erase(st.find(f[t2][0]));
					
					int cur=0;
					int t=INF;
					for(int k=0;k<=K;k++){
						if(sz[i]<k) continue;
						if(sz[j]<K-k) continue;
						ckmin(t,max(f[i][k],f[j][K-k]));
					}
					ckmax(cur,t);
					ckmax(cur,max(dep[i],dep[j])-1);
					if(st.size()) ckmax(cur,*st.begin());
					if(p1.fi>1) ckmax(cur,query(1,1,n,1,p1.fi-1));
					if(p2.fi-1>p1.se) ckmax(cur,query(1,1,n,p1.se+1,p2.fi-1));
					if(p2.se<n) ckmax(cur,query(1,1,n,p2.se+1,n));
					
					ckmin(ans,cur);
					
					st.insert(f[t1][0]);
					if(t2!=t1) st.insert(f[t2][0]);
				}
			}
			return ans;
		}
	}
	
	int Solve(){
		cin>>n>>K;
		for(int i=0;i<=n;i++) edge[i].clear();
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			edge[u].pb(v);edge[v].pb(u);
		}
		return GET50PTS::solve();
	}
	
	signed main(){
		ios::sync_with_stdio(0);cin.tie(0);
		freopen("hub.in","r",stdin);
		freopen("hub.out","w",stdout);
		cin>>C>>T;
		while(T--)
			cout<<Solve()<<"\n";
		return 0;
	}
}signed main(){return Zhchz::main();}
