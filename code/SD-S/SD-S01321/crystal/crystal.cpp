#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define fst ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n" 
#define popcount(x) __builtin_popcountll(x)
#define pii pair<int,int>
#define fi first
#define se second
#define inf 1000000000
#define infll 1000000000000000000ll
#define lowbit(x) (x&-x)
using namespace std;
ll qpow(ll a,ll n){ll res=1;while(n){if(n&1)res=res*a;a=a*a;n>>=1;}return res;}
ll qpow(ll a,ll n,ll p){ll res=1;while(n){if(n&1){res=res*a%p;}a=a*a%p;n>>=1;}return res;}
ll gcd(ll a,ll b){if(!b)return a;return gcd(b,a%b);}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
const int N=5e5+99;
int n;
ll m,a[N];
ll sum[N];
bool check(int x,int r){
	return 1ll*(r-x)*a[r]-(sum[r-1]-sum[x-1])<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	fst;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		int res=i;
		while(l<=r){
			int mid=l+r>>1;
			if(check(mid,i)){
				r=mid-1;
				res=mid;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-res+1);
	}
	cout<<ans<<endl;
	return 0;
}
