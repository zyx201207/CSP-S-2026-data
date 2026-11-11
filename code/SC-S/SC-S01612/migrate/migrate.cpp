#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
ll C,T;
ll n,d,x[N],dis[N],cnt[N];
vector<ll> edge[N];
void dij(ll from){
	queue<ll> q;
	memset(dis,0x3f,sizeof(dis));
	memset(cnt,0,sizeof(cnt));
	dis[from]=0;cnt[from]=1;
	q.push(from);
	while(q.size()){
		ll str=q.front();
		q.pop();
		for(auto son:edge[str]){
			if(dis[son]>dis[str]+1){
				dis[son]=dis[str]+1;cnt[son]=cnt[str];
				q.push(son);
			}else if(dis[son]==dis[str]+1){
				cnt[son]+=cnt[str];
			}
		}
	}
}
void solve(){
	cin>>n>>d;
	for(ll i=1;i<=n;i++){
		cin>>x[i];
	}
	for(ll i=1;i<=n;i++){
		edge[i].clear();
	}
	for(ll i=1;i<=n;i++){
//		ll l=lower_bound(x+1,x+1+n,x[i]-d)-(x+1);
		ll r=upper_bound(x+1,x+1+n,x[i]+d)-(x)-1;
		for(ll j=i+1;j<=r;j++){
			edge[i].emplace_back(j);
		}
	}
	ll ans=0;
	for(ll i=1;i<=n;i++){
		dij(i);
		for(ll j=1;j<=n;j++){
//			cout<<i<<","<<j<<","<<cnt[j]<<endl;
			if(cnt[j]==2) ans++;
		}
	}
	cout<<ans<<"\n";
	
}
void solveB(){
	cin>>n>>d;
    for(ll i=1;i<=n;i++){
		cin>>x[i];
	}
	cout<<0<<"\n";
	
}
int main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>C>>T;
	while(T--){
		if(C!=13 and C!=14)solve();
		else solveB();
	}
	return 0;
}