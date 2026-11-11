#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define inf 1000000000000000000
#define vec vector<ll>
#define pii pair<ll,ll>
#define all(x) x.begin(),x.end()
using namespace std;

ll max(ll a,ll b){return (a<b?b:a);}
ll min(ll a,ll b){return (a>b?b:a);}
ll lowbit(ll x){return x&(-x);}
ll ksm(ll a,ll d,ll mo=mod){
	a%=mo;
	ll ans=1;
	for(;d;d>>=1){
		if(d&1)ans=ans*a%mo;
		a=a*a%mo;
	}
	return ans;
}

ll n,m,a[500005],sum[500005],lp,rp,mid,ans,t1;

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	t1=0;
	for(int i=1;i<=n;i++){
		lp=1;rp=i;ans=0;
		while(lp<=rp){
			mid=(lp+rp)/2;
			if(sum[i]-sum[mid-1]+m>=a[i]*(i-mid+1)){
				ans=mid;
				rp=mid-1;
			}else{
				lp=mid+1;
			}
		}
		t1=max(t1,i-ans+1);
	}
	cout<<t1<<'\n';
}

int main(){
//  system("fc crystal5.ans crystal.out");return 0;
//	freopen("crystal5.in","r",stdin);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
//	ll t;
//	for(cin>>t;t;t--)
	solve();
	
	return 0;
}

/*
显然所有加了的水晶都会被用到。
那么，假设加到了k
一定有k，且选的数一定是小于k的极大
考虑遍历k，然后二分后面能取多少。 

*/
