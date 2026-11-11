#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
const int mod=998244353;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int N=5e5+10;
ll n,m;
ll a[N];
ll b[N];
ll c[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	FAST
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	for(int i=2;i<=n;i++){
		c[i]=c[i-1]+(i-1)*b[i];
	}
	ll ans=0;
	for(int i=2;i<=n;i++){
		ll l=1,r=i;
		ll h=c[i-1];
		while(l<r){
			ll mid=(l+r)>>1;
			ll j=(i-mid)*b[i];
			ll z=c[mid]+(a[i-1]-a[mid])*(mid-1);
			if(h-z+j<=m){
				r=mid;
				ans=max(ans,i-mid+1);
			}else{
				l=mid+1;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9
*/
/*
5 8
-3 -1 2 2 7
*/
