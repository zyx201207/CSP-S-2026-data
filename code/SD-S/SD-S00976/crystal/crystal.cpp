#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll N=5e5+5;
ll n,m,a[N],s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(ll i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;++i)s[i]=s[i-1]+a[i];
	ll l=0,ans=1;
	for(ll r=1;r<=n;++r){
		while(l<r&&a[r]*(r-l)-(s[r]-s[l])>m)++l;
		ans=max(ans,r-l);
	}
	cout<<ans;
	return 0;
}

