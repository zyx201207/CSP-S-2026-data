#include<bits/stdc++.h>
#define now_time ((int)(((double)clock()/CLOCKS_PER_SEC)*1000))
#define all_memory ((&St-&Ed)/1024.0/1024.0)

using namespace std;
using ll=long long;

namespace Usd{bool St;}

constexpr ll N=2e6;
constexpr ll Imax=0x3f3f3f3f3f3f3f3f;

ll subtask,T;
ll n,d,x[N+5];
ll f[N+5],g[N+5];

namespace solve_A{
	int main(){
		while(T--){
			cin>>n>>d;
			for(ll i=1;i<=n;++i){
				cin>>x[i];
			}
			if(n==1||d<=(x[2]-x[1])||d/(x[2]-x[1])==1){cout<<"0\n";continue;}
			cout<<max(0ll,n-(d/(x[2]-x[1])*2ll-1ll))<<"\n";
		}
		return 0;
	}
}

namespace Usd{bool Ed;void out(){cerr<<"   time: "<<now_time<<"ms\n memory: "<<all_memory<<"MiB\n";}}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>subtask>>T;
	if(subtask>=11&&subtask<=12) return solve_A::main();
	while(T--){
		cin>>n>>d;
		for(ll i=1;i<=n;++i) cin>>x[i];
		ll ans=0;
		for(ll i=1;i<=n;++i){
			f[i]=0,g[i]=1;
			ll mn_l=i,mn_r=i,sum_g=1;
			for(ll j=i+1;j<=n;++j){
				f[j]=Imax,g[j]=0;
				while(mn_l<j&&x[j]-x[mn_l]>d){
					sum_g-=g[mn_l];
					++mn_l;
				}
				if(mn_l>mn_r) mn_r=mn_l,sum_g=g[mn_l];
				while(mn_r+1<j&&f[mn_r+1]==f[mn_l]){
					++mn_r;
					sum_g+=g[mn_r];
				}
				f[j]=f[mn_l]+1;
				g[j]=sum_g;
				if(g[j]==2) ++ans;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
