#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m;
const ll maxn=5e5+7;
const ll n2_maxn=5007;
ll a[maxn],suf[maxn];
ll cost1[n2_maxn][n2_maxn],cost_prefix[n2_maxn][n2_maxn];
ll ai;

bool is0=1;
bool isequal=1;


int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

  	ios::sync_with_stdio(0);
  	cin.tie(0);
  	cout.tie(0);


	cin>>n>>m;
	for (ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (ll i=1;i<=n;i++){
		suf[i]=a[i]-a[i-1];
		if (i>1 && suf[i]!=0) is0=0;
		if (i>2 && suf[i]!=suf[i-1]) isequal=0;
//		cost[i]=suf[i]*(i-1);
	}
	
	
	if(is0){
		cout<<n;
		return 0;
	}
	if (n>=5 && isequal){
		ll d=suf[2];
		ll ans=0;
		for (ll i=1;i<=n;i++){
			ll cost2=d*((1+i)*i/2);
//			cout<<"cost2="<<cost2<<"\n";
			if (cost2<=m) ans=max(ans,i);
			else break;
		}
		cout<<ans;
		return 0;
	}

//O(N^2)
	
	ll ans=-1e18;
	for (ll r=n;r>=1;r--){
		for (ll l=r-1;l>=1;l--){
			cost1[l][r]=cost1[l+1][r]+suf[l+1];
			cost_prefix[l][r] = cost_prefix[l+1][r] + cost1[l][r];
			
			if (cost_prefix[l][r]<=m) ans=max(ans , r-l+1);
			else break;
			
//			printf("l=%lld r=%lld %lld \n",l,r,cost_prefix[l][r]);
		
		}
	}
	cout<<ans<<"\n";
}


