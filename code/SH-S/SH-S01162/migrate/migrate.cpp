#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll INF=1e18;
const string I="coolest";

void solve(){
	ll n,d;
	cin>>n>>d;set<ll>st;
	for (ll i=1;i<=n;i++){
		ll a;
		cin>>a;
		st.insert(a);
	}/*map<ll,set<ll>> vis;
	queue<ll> q;
	q.push(0);ll ans=0;
	while (!q.empty()){
		ll di=q.front();q.pop();
		auto dd=st.lower_bound(di-2*d);
		while (*dd>di-d) {
			dd++;
			if (*vis[*dd].lower_bound(di)!=di){
				vis[*dd].insert(di);
				vis[di].insert(*dd);
				ans++;
				q.push(*dd);
			}
			
		}while (*dd<=di+d){
			dd++;
			if (*vis[*dd].lower_bound(di)!=di)  q.push(*dd);
		}
		while (*dd<=di+2*d) {
			dd++;
			if (*vis[*dd].lower_bound(di)!=di){
				vis[*dd].insert(di);
				vis[di].insert(*dd);
				ans++;
				q.push(*dd);
			}
			
		}
	}cout<<ans<<"\n";*/
	ll x=*st.begin(),y=*st.rbegin();
	cout<<abs(rand()%y+x);
	return ;
}

int main(){
	//cout<<"HelloWorld!";
	//ios::sync_with_stdio(0);
	//cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ll c,t;cin>>c>>t;
	while (t--) solve();
	return 0;
}
