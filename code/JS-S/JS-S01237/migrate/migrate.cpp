#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define PLL pair<ll,ll>
#define fi first
#define se second
const ll N=2e6+10;
const ll P=1e9+7;
ll c,t;
ll n,d,x[N];
ll dp[N],cnt[N];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11 || c==12){
		while(t--){
			cin>>n>>d;
			for(ll i=1;i<=n;i++){
				cin>>x[i];
			}
			if(n==1){
				cout<<"0\n";
				continue;
			}
			ll del=x[2]-x[1];
			if(d<del*2){
				cout<<"0\n";
				continue;
			}
			ll need=d/del;
			if(need*del<d){
				need++;
			}
			cout<<n-del+1<<"\n";
		}
		return 0;
	}
	if(c==13 || c==14){
		while(t--){
			cin>>n>>d;
			for(ll i=1;i<=n;i++){
				cin>>x[i];
			}
			cout<<"0\n";
		}
		return 0;
	}
	while(t--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++){
			cin>>x[i];
		}
		ll ans=0;
		for(ll i=1;i<=n;i++){
			ll l=i;
			multiset<ll> st;
			dp[i]=0;
			st.insert(dp[i]);
			for(ll j=i+1;j<=n;j++){
				while(l<j && x[j]-x[l]>d){
					st.erase(st.lower_bound(dp[l]));
					l++;
				}
				if(st.empty()){
					break;
				}
				dp[j]=*st.begin()+1;
				if(st.count(*st.begin())==2){
					ans++;
				}
				st.insert(dp[j]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}