#include <cstdio>
using namespace std;
#define ll long long

const int N=2e6+9;
int n;
ll x[N],d;

int dfs(int u,int r,int cur,int cnt) {
	if(u==r) return cur==cnt;
	int ret=0;
	for(int v=u+1;v<=r;v++) {
		if(x[v]-x[u]<=d) {
			ret+=dfs(v,r,cur+1,cnt);
		}
	}
	return ret;
}

void solve() {
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
	int ans=0;
	for(int len=3;len<=n-1;len++) {
		for(int l=1;l+len<=n;l++) {
			int r=l+len,cnt=0;
			ll cur_dis=0;
			for(int k=l+1;k<=r;k++) {
				if(cur_dis+x[k]-x[k-1]>=d) {
					cur_dis=x[k]-x[k-1];
					cnt++;
				} else cur_dis+=x[k]-x[k-1];
			}
			if(dfs(l,r,0,cnt)==2) ans++;
		}
	}
	printf("%d\n",ans);
}

void solve_for_A() {
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
	ll p=x[2]-x[1];
	ll f=d/p,ans=0;
	if(f==0) {
		puts("0");
		return;
	}
	for(ll len=f+1;len<=n-1;len++) if(len%f) ans+=(n-len);
	printf("%lld\n",ans);
}

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--) {
		if(11<=c && c<=12) 
			solve_for_A();
		solve();
	}
	return 0;
}