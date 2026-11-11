#include <bits/stdc++.h>
using namespace std;
using uint = unsigned;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,l,r) for(int i=(l);i>=(r);--i)
#define repn(i,n)  for(int i=0;i<(n);++i)
#define sizc(x) (int((x).size()))
#define allc(x) (x).begin(),(x).end()
#define fir first
#define sec second

constexpr int N=2e6+5;

int tc,n;
ll m,a[N];

int pl[N],pr[N];
ll f0[N],f1[N];

ll solve(int l,int r){
	pl[l]=pr[r]=0;
	int p=l;rep(i,l+1,r){
		while(a[i]-a[p]>m)++p;
		pl[i]=p; 
	}
	p=r;per(i,r-1,l){
		while(a[p]-a[i]>m)--p;
		pr[i]=p;
	}
	rep(i,l,r)f0[i]=f1[i]=0;
	ll ans=0;
	rep(i,l,r){
		if(pr[pl[i]]==i){// mid 0
			int j=pl[i];
			f0[i]+=f0[j],f1[i]+=f1[j];
		}
		if(pr[pl[i]]>=i){//end 0
			int j=pl[i];
			ans+=f1[j];
		}
		if(pl[pr[i]]<=i){// begin 0
			int j=pr[i];
			++f0[j];
		}
		if(pl[pl[i]]){// mid 1
			int p=pl[i],q=pl[pl[i]];
			if(pr[pr[q]]==i&&pr[q]==p+1)f1[i]+=f0[q];
		}
		if(pl[pl[i]]){// end 1
			int p=pl[i],q=pl[pl[i]];
			if(pr[pr[q]]>=i&&pr[q]==p+1)ans+=f0[q];
		}
		if(pr[pr[i]]){// begin 1
			int p=pr[i],q=pr[pr[i]];
			if(pl[pl[q]]<=i&&pl[q]==p-1)++f1[q];
		}
	}
	// onestep
	p=l;int q=l;
	rep(i,l,r)if(pr[pr[i]]){
		while(p<=r&&pl[p]<pr[i]-1)++p;
		while(q<=r&&pl[q]<pr[i])++q;
		int tl=max(pr[i],p-1),tr=min(pr[pr[i]],q-1);
		ans+=max(tr-tl,0); 
	}
	return ans;
}

void solve(){
	cin>>n>>m;
	rep(i,1,n)cin>>a[i];
	ll ans=0;
	rep(i,1,n){
		int j=i;while(j<n&&a[j+1]-a[j]<=m)++j;
		ans+=solve(i,j),i=j; 
	}
	cout<<ans<<'\n';
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;cin>>tc>>T;
	while(T--)solve();
}
