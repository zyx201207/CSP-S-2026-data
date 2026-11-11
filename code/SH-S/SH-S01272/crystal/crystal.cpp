#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m,a[N],d[N],s[N],s2[N];
ll ans=1;
bool check(ll i,ll x){
	return (x-i)*s[x]-s2[x-1]+s2[i-1]<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++) d[i]=a[i]-a[i-1];
	for(int i=1;i<=n;i++) s[i]=s[i-1]+d[i];
	for(int i=1;i<=n;i++) s2[i]=s2[i-1]+s[i];
	for(ll i=1;i<=n;i++){
		ll l=i+1,r=n;
		while(l<=r){
			ll mid=(l+r)/2;
			if(check(i,mid)) l=mid+1;
			else r=mid-1;
		}
		ans=max(ans,r-i+1);
	}
	cout<<ans<<'\n';
//	for(int i=1;i<=n;i++) cout<<d[i]<<' '; cout<<endl;
//	for(int i=1;i<=n;i++) cout<<s[i]<<' '; cout<<endl;
//	for(int i=1;i<=n;i++) cout<<s2[i]<<' ';
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
