#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+5;
ll n,m;
ll a[N];
ll q[N];
ll tot=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	ll l=1,ans=1,sum=0;
	q[++tot]=1;
	for(ll i=2;i<=n;i++){
		sum+=(a[i]-a[i-1])*(i-l);
		while(sum>m){
			sum-=(a[i]-a[l]);
			++l;
		}
		q[++tot]=i;
		ans=max(ans,i-l+1);
	} 
	cout<<ans<<"\n";
	return 0;
} 
