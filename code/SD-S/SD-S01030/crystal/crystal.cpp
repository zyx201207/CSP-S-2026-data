#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pal pair<ll,ll>
#define fi first
#define se second
const ll MOD=1e9+7;
const ll N=5e5+10;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll n,m,a[N];
void Solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll cnt=1,ma=0;
	ll x=0;
	for(ll i=1;i<=n;i++){
		x=x+(i-cnt)*(a[i]-a[i-1]);
		while(x>m){
			x-=a[i]-a[cnt];
			cnt++;
		}
		ma=max(ma,i-cnt+1);
	}
	cout<<ma;
} 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll T=1;//cin>>T;
	while(T--)Solve();
	return 0;
}
