#include <iostream>
#include <vector>
#include <algorithm>
#include <string> 

using namespace std;
using ll=long long;

const ll INF = 4e18; 
const int N = 500005;
ll n,m;
ll a[N];
ll sum[N];
ll ans; 


int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	ans = -INF; 
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=1; 
	}
	sort(a+1,a+n+1);

	for(ll t=1;t<=n;t++){ 
		ll i=t;
		ll j=t+1;
		ll r=m;
		while(j<=n && a[j]-a[i]<=r){
			r-=a[j]-a[i];
			j++;
			i++;
			sum[t]++;
		}
		ans = max(ans,sum[t]); 
	}
	
	cout<<ans;
	
	return 0;
}

