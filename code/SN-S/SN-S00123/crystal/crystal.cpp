#include<bits/stdc++.h>
#define ll long long
#define N 500005
using namespace std;

namespace WDY_Hodur{

ll n,m,ans;
ll a[N],s[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	
	for(ll l=0,r=1;r<=n;r++){
		while(s[r]-s[l]+m<a[r]*(r-l)&&l<r)++l;
		ans=max(ans,r-l);
	}
	
	cout<<ans;
	return 0;
}

}

int main(){
	WDY_Hodur::main();
	return 0;
}
