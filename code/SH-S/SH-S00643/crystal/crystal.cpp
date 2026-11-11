#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lf double
#define vc vector
#define pb push_back
const ll N=5e5+5;
ll n,m,ans;
ll a[N],s[N];
bool check(ll mid,ll x){
	return a[x]*(x-mid)-(s[x-1]-s[mid-1])<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++){
		s[i]=a[i]+s[i-1];
		ll l=1,r=i,k=i;
		while(l<=r){
			ll mid=(l+r)>>1;
			if(check(mid,i)){
				k=mid,r=mid-1;
			}else{
				l=mid+1;
			}
		}
//		cout<<i<<' '<<k<<'\n';
		ans=max(i-k+1,ans);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
