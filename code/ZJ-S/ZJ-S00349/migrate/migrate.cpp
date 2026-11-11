#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e6+10;
ll c,t;
ll n,d;
ll a[N];
bool flag=0;
ll cnt[N];
ll dis[N];
ll minn=1e9;
void dfs(ll x,ll y,ll now){
//	cout<<x<<" "<<y<<" "<<now<<" "<<cnt[x]<<"\n";
	if(x>y) return;
	if(flag) return;
	for(ll i=y;i>=x+1;i--){
		if(a[i]-a[x]>d) continue;
		if(dis[i]==now+1) cnt[i]++;
		else if(dis[i]<now+1) return;
		else{
			cnt[i]=1;
			dis[i]=now+1;
		}
//		cout<<dis[i]<<" "<<x<<" "<<i<<" "<<y<<" "<<now+1<<"\n";
		dfs(i,y,now+1);
	}
}
void work(){
	cin>>n>>d;
	for(ll i=1;i<=n;i++) cin>>a[i];
	if(c<=10){
		ll ans=0;
		for(ll u=1;u<=n;u++){
			for(ll v=u+1;v<=n;v++){
				flag=0;
				minn=1e9;
				for(ll i=u;i<=v;i++) cnt[i]=0,dis[i]=INT_MAX;
				dis[u]=0;
				dfs(u,v,0);
//				cout<<"\n";
				if(!flag&&cnt[v]==2){
					ans++;
//					cout<<u<<" "<<v<<"\n";
				}
			}
		}
		cout<<ans<<"\n";
	}else if(c<=12){
		ll x=abs(a[2]-a[1]);
		ll y=d/x;
		if(y<=1ll) cout<<"0\n";
		else cout<<max(0ll,n-y-y+1)<<"\n";
	}else{
		cout<<"0\n";
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
//	t=1;
	while(t--) work();
	return 0;
}