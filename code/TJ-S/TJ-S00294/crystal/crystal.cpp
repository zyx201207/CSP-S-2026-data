#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ll NEG=-1e18;
const ll INF=1e18;
const ll MAXN=5e5+99;
ll n,m;
ll ans=NEG;
ll a[MAXN];
vector<ll> v;
ll s[MAXN];
map<ll,ll> cnt;
bool check(ll k){
	ll it=lower_bound(v.begin(),v.end(),k)-v.begin();
	ll res=it;
	if(a[it+1]==k){
		res+=cnt[k];
	}
	ll cost=0;
	cost+=k*it-s[it];
	if(cost<=m){
		ans=max(ans,res);
		return true;
	}else{
		return false;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	ll Max=NEG;
	ll Min=INF;
	bool A=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			A=false;
		}
		cnt[a[i]]++;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		v.push_back(a[i]);
		s[i]=s[i-1]+a[i];
		Min=min(Min,a[i]);
		Max=max(Max,a[i]);
	}
	for(int i=Min;i<=Max;i++){
		check(i);
	}
	ll l=Min,r=Max;
	while(l<r){
		ll mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
		}else{
			r=mid;
		}
	}
	cout<<ans<<endl;
	return 0;
} 







