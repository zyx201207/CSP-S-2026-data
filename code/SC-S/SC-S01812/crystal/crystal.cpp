//O(2n)
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll; 
ll a[500010];
ll n,res;
ll m,ans; 

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++)scanf("%lld",&a[i]); 
	sort(a+1,a+n+1);
	for(ll r=2,l=1;r<=n;r++){ //当r作为等值时，l的最小值 
		ans+=(r-l)*(a[r]-a[r-1]); 
		while(ans>m&&l<r){ //O(n)
			ans-=a[r]-a[l]; 
			l++;
		}
		res = max(r-l+1,res);
	}
	printf("%lld",res);
	return 0;
}
