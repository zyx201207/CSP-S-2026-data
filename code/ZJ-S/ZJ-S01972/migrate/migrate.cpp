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
//#############################################################
#define DEBUG 0

expr int N = 2e6+5;
int n,pr[N],nx[N],ans_l[N],ans_r[N];
LL a[N],ans,d,sum_l[N],sum_r[N];

void work() {
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	nx[0] = 0, pr[n+1] = n+1;
	for(int i=1,j=1;i<=n;i++) {
		while(j<n && a[j+1]-a[i]<=d) j++;
		nx[i] = j;
	}
	for(int i=n,j=n;i>=1;i--) {
		while(j>1 && a[i]-a[j-1]<=d) j--;
		pr[i] = j;
	}
	printf(">>> pr: "); db for(int i=1;i<=n;i++) printf("%d ",pr[i]); printf("\n");
	printf(">>> nx: "); db for(int i=1;i<=n;i++) printf("%d ",nx[i]); printf("\n");
	for(int l=1;l<=n;l++) {
		int mid = nx[l];
		if(mid<l+2) continue;
		int mx_r = min(n,nx[mid-1]);
		int mi_r = max(mid+1,nx[mid-2]+1);
		if(mi_r<=mx_r) ans += mx_r-mi_r+1;
	}
	printf("### tot_A = %lld\n",ans);
	{
		printf("--------------------------------------------\n");
		for(int i=n;i>=1;i--) {
			int min_r = max(i+1,nx[i-1]+1);
			int max_r = min(n,nx[i]);
			if(min_r<=max_r) ans_r[i] += max_r-min_r+1;
			ckmax(min_r,nx[i]), ckmin(max_r,nx[i]);
			if(min_r<=max_r) ans_r[i] += ans_r[nx[i]];
			sum_r[i] = sum_r[i+1]+ans_r[i];
		}
		for(int i=1;i<=n;i++) {
			int max_l = min(i-1,pr[i+1]-1);
			int min_l = max(1,pr[i]);
			printf(">>> l[%d] = [%d,%d]\n",i,min_l,max_l);
			if(min_l<=max_l) ans_l[i] = max_l-min_l+1;
			ckmax(min_l,pr[i]), ckmin(max_l,pr[i]);
			if(min_l<=max_l) ans_l[i] += ans_l[pr[i]];
			sum_l[i] = sum_l[i-1]+ans_l[i];
		}
	}
	printf(">>> ans_l: "); db for(int i=1;i<=n;i++) printf("%d ",ans_l[i]); printf("\n");
	printf(">>> ans_r: "); db for(int i=1;i<=n;i++) printf("%d ",ans_r[i]); printf("\n");
	db { //brute
		for(int i=1;i<=n;i++) {
			static int dis[N],way[N];
			memset(dis,0,n+3<<2);
			memset(way,0,n+3<<2);
			queue<int>q;
			dis[i] = way[i] = 1, q.push(i);
			while(_sz(q)) {
				int x = q.front(); q.pop();
				for(int i=pr[x];i<=nx[x];i++) {
					int tmp = dis[x]+1;
					if(!dis[i]) {
						dis[i] = tmp, way[i] = way[x];
						q.push(i);
					} else if(dis[i]==tmp) {
						way[i] += way[x];
					}
				}
			}
			for(int j=i+1;j<=n;j++) {
				if(way[j]==2) {
					printf("\t--- pair: (%d,%d) --> ",i,j);
					auto getnx=[&](int x) { return min(j,nx[x]); };
					auto getpr=[&](int x) { return max(i,pr[x]); };
					vi go = {i};
					while(go.back()<j) go.pb(getnx(go.back()));
					vi inv = {j};
					while(inv.back()>i) inv.pb(getpr(inv.back()));
					reverse(_all(inv));
					int id = 0;
					for(int i=0;i<_sz(go);i++)
						if(go[i]!=inv[i]) id = i;
					if(_sz(go)==3) {
						printf("A");
					} else if(id>1 && id==_sz(go)-2) {
						printf("C, core = [%d,%d]",go[id-1],go[id+1]);
					} else if(id==1) {
						printf("B, core = [%d,%d]",go[id-1],go[id+1]);
					} else {
						printf("D, core = [%d,%d]",go[id-1],go[id+1]);
					}
					printf("\n");
				}
			}
		}
	}
	for(int l=1;l<=n;l++) {
		int mid = nx[l];
		if(mid<l+2) continue;
		int r = nx[mid];
		if(pr[r]!=mid-1) continue;
		if(l<mid && mid<r) {
			ans += ans_r[r];
			db if(ans_r[r]) printf("B[%d,%d] = %d\n",l,r,ans_r[r]);
		}
	}
	printf("### tot_B = %lld\n",ans);
	for(int r=1;r<=n;r++) {
		int mid = pr[r];
		if(mid>r-2) continue;
		int l = pr[mid];
		if(nx[l]!=mid+1) continue;
		if(l<mid && mid<r) {
			ans += ans_l[l];
			db if(ans_l[l]) printf("C[%d,%d] = %d\n",l,r,ans_l[l]);
		}
	}
	printf("### tot_C = %lld\n",ans);
	for(int l=1;l<=n;l++) {
		int mid = nx[l];
		if(mid<l+2) continue;
		int r = nx[mid];
		if(pr[r]!=mid-1 || pr[mid-1]!=l) continue;
		if(!(l<mid && mid<r)) continue;
		ans += (LL)ans_l[l]*ans_r[r];
	}
	printf("### tot_D = %lld\n",ans);
	cout<<ans<<'\n';
}
void clear() {
	#define cl(x) memset(x,0,(n+3)*sizeof(*x));
	cl(pr)cl(nx)cl(ans_l)cl(ans_r)cl(a)
	cl(sum_l)cl(sum_r)
	ans = d = 0;
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ndb ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int sub,T; cin>>sub>>T;
	while(T--) work(),clear();
	return 0;
}
/*

*/