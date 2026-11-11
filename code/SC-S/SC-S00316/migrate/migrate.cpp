#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 300+10;
ll c, t, n, d;
ll a[N];
vector<ll> G[N];
ll maxn[N];
ll minn=1e17,ans=0;
void dfs(ll x,ll to,ll step){
	//cout<<"<><><> "<<x<<"  "<<to<<"  "<<step<<"\n";
	if(x>to) return;
	if(ans>2) return;
	if(x==to){
		if(step<minn){
			minn=step;
			ans=1;
		}else if(step==minn){
			ans++;
		}
		return;
	}
	if(step>=minn) return;
	for(ll i=x+1;i<=maxn[x];i++){
		dfs(i,to,step+1);
	}
	return;
}
ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	c=read(),t=read();
	while (t--) {
		memset(a, 0, sizeof a);
		ll cnt=0;
		n=read(),d=read();
		for (ll i = 1; i <= n; i++) a[i]=read();
			for(ll i=1;i<=n;i++){
				maxn[i]=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
			//	cout<<"< "<<maxn[i]<<"\n";
			}
			for(ll i=1;i<n;i++){
				for(ll j=i+1;j<=n;j++){
					ans=0;
					minn=1e17;
					dfs(i,j,0);
					//cout<<"<< minn: "<<minn<<" ans: "<<ans<<"\n";
					if(ans==2){
						cnt++;
					}
				}
			}
			cout<<cnt<<"\n";
		}
	
	return 0;
}