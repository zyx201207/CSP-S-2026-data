#include <bits/stdc++.h>
using namespace std;

#define expr constexpr
#define db if(DEBUG)
#define ndb if(!DEBUG)
#define printf db printf
#define P pair<int,int>
#define F first
#define S second
#define pb push_back
#define ass(x) if(!(x)) cerr<<"ERROR on line "<<__LINE__<<endl,exit(1);
#define _sz(x) int((x).size())
#define _all(x) (x).begin(),(x).end()
typedef long long LL;
typedef __int128 i28;
#define vi vector<int>

template<typename T>void ckmin(T&x,const T&y) { if(y<x) x=y; }
template<typename T>void ckmax(T&x,const T&y) { if(x<y) x=y; }
mt19937_64 rnd(20110603 & 5201314);
LL Rand(LL l,LL r) { return rnd()%(r-l+1)+l; }
//#####################################################################################################
#define DEBUG 0

expr int N = 1e6+5, inf = 1e9;
vi v[N];
bool vis[N];
int sub,T,n,k,mid;

int fa[N];
int getfa(int x) { return x==fa[x]?x:fa[x]=getfa(fa[x]); }
void work() {
	cin>>n>>k;
	for(int i=1,x,y;i<n;i++)
		cin>>x>>y,v[x].pb(y),v[y].pb(x);
	if(k==n) return cout<<"0\n",void();
	if(sub>=1 && sub<=3) {
		printf("#################################################\n");
		static int dis[105][105];
		memset(dis,0x3f,sizeof dis);
		for(int i=1;i<=n;i++) {
			dis[i][i] = 0;
			for(int j:v[i]) dis[i][j] = 1;
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++)
					ckmin(dis[j][k],dis[j][i]+dis[i][k]);
		int ans = n+5;
		for(int i=0;i<1<<n;i++) {
			if(__builtin_popcount(i)==k) {
				static bool vis[100];
				memset(vis,0,n+3);
				iota(fa+1,fa+1+n,1);
				for(int j=1;j<=n;j++) vis[j] = i>>j-1&1;
				printf(">>> set: "); db for(int j=1;j<=n;j++) if(vis[j]) printf("%d ",j); printf("\n");
				for(int j=1;j<=n;j++) for(int k:v[j]) if(vis[j] && vis[k]) fa[getfa(j)]=fa[getfa(k)];
				memset(vis,0,n+3);
				for(int j=1;j<=n;j++) if(i>>j-1&1) vis[getfa(j)]=1;
				if(accumulate(vis+1,vis+1+n,0)<=2) {
					printf("\t--- good!\n");
					int mx = 0;
					for(int j=1;j<=n;j++) {
						if(~i>>j-1&1) {
							int mi = n+5;
							for(int k=1;k<=n;k++)
								if(i>>k-1&1) ckmin(mi,dis[j][k]);
							ckmax(mx,mi);
						}
					}
					ckmin(ans,mx);
				}
			}
		}
		cout<<ans<<'\n';
		return;
	}
	if(k==2) {
		printf("#####################################################\n");
		auto calc=[&]() -> int {
			int ans = 0;
			auto dfs=[&](auto&&sf,int fa,int x) -> int {
				vi res;
				for(int y:v[x]) if(y!=fa) res.pb(sf(sf,x,y));
				if(!_sz(res)) return 1;
				int mi = *min_element(_all(res));
				int mx = *max_element(_all(res));
				if(mi+mx<0) return mi+1;
				int k = mx+1;
				if(k>mid) {
					ans++;
					return -mid;
				}
				return k;
			};
			int res = dfs(dfs,0,1);
			if(res>0) ans++;
			printf("--- calc(%d) = %d\n",mid,ans);
			return ans;
		};
		int l = 1, r = n-1;
		while(l<=r) {
			mid = l+r>>1;
			if(calc()<=k) r = mid-1;
			else l = mid+1;
		}
		cout<<l<<'\n';
		return;
	}
	if(sub==13 || sub==14) {
		int m = n>>1;
		auto calc=[&]() -> int {
			if(mid>=m+1) return 1;
			if(mid>=m+1>>1) return 1;
			int mi = mid, mx = m+1-mid;
			return mx-mi+1;
		};
		int l = 1, r = n-1;
		while(l<=r) {
			mid = l+r>>1;
			if(calc()<=k) r = mid-1;
			else l = mid+1;
		}
		cout<<l<<'\n';
		return;
	}
}
void clear() {
	for(int i=1;i<=n;i++) v[i].clear();
	#define cl(x) memset(x,0,(n+3)*sizeof(*x));
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ndb ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);	
	cin>>sub>>T;
	while(T--) work(),clear();
	return 0;
}