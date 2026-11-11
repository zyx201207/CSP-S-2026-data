#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define fi first
#define se second
#define mk make_pair
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll maxn=500009;
ll n,m,a[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	rep(i,1,n)	cin>>a[i];
	sort(a+1,a+1+n);
	ll l=1,ans=1,now=0;
	rep(i,2,n){
		now+=(i-l)*(a[i]-a[i-1]);
		while(now>m)	now-=(a[i]-a[l]),l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
