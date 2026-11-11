#include<bits/stdc++.h>
#define ll long long
#define mid ((l+r)>>1)
using namespace std;

ll n,a[500004],cnt,ans,m,s[500005];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	ll l=1;
	for(ll r=1;r<=n;r++){
		while((a[r]*1ll*(r-l+1))-(s[r]-s[l-1])>m){
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans<<'\n';
	return 0;
}
