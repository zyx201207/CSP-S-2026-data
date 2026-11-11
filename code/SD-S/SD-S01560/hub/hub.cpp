#include<bits/stdc++.h>
#include<queue>
#define ll long long
#define mp make_pair
#define ft first
#define sd second
#define pb push_back
#define pe(i) (1ll<<(i))
#define endl "\n"
using namespace std;
const ll N=3e6+5,INF=0x3f3f3f3f3f3f3f3f;
ll n,k;
vector<ll> e[N],e1[N];
ll bo[N],bob[N];
namespace sub1{
	void ddfs(ll x,ll la){
		bob[x]=1;
		for(int i:e1[x]){
			if(i==la)continue;
			ddfs(i,x);
		}
	}
	ll dep[N];
	void dfs(ll x,ll la){
		dep[x]=dep[la]+1;
		for(int i:e[x]){
			if(i==la)continue;
			dfs(i,x);
		}
	}
	ll cl(ll x,ll la,ll de){
		if(bo[x]) return de;
		ll ans=INF;
		for(int i:e[x]){
			if(i==la)continue;
//			cout<<x<<" "<<i<<endl;
			ans=min(ans,cl(i,x,de+1));
		}
		return ans;
	}
	void sovle(){
		dfs(1,0);
		ll ans=INF;
		for(int s=1;s<pe(n);s++){
			ll su=0;
			for(int j=1;j<=n;j++) if(s&pe(j-1)) bo[j]=1,su++;
			else bo[j]=0;
			if(su!=k)continue;
			for(int j=1;j<=n;j++) e1[j].clear(),bob[j]=0;
			for(int j=1;j<=n;j++) if(bo[j]){
				for(int k:e[j]) if(bo[k]) e1[j].pb(k);
			}
			ll sus=0;
			for(int i=1;i<=n;i++) if(bo[i]&&!bob[i]) ddfs(i,0),sus++;
			if(sus>2)continue;
			ll an=-INF;
//			for(int i=1;i<=n;i++) cout<<bo[i]<<" ";cout<<endl;
//			for(int i=1;i<=n;i++) cout<<cl(i,0,0)<<' ';cout<<endl<<endl;
			for(int i=1;i<=n;i++){
				an=max(an,cl(i,0,0) );
			}
			ans=min(ans,an);
		}
		cout<<ans<<endl;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ll c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1,u,v;i<=n;i++) e[i].clear();
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			e[u].pb(v);e[v].pb(u);
		}
		sub1::sovle();
//		if(c<=3){
//		}
	}
	return 0;
} 
