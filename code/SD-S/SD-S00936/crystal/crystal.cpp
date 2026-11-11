#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans=1;
ll a[500001];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1; i<=n; i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=n; i>=1; i--) {
		ll k=0,s=i-1,cnt=1;
		while(k+a[i]-a[s]<=m&&s!=0) {
			k+=a[i]-a[s];
			cnt++;
			s--;
		}
		if(cnt>ans)ans=cnt;
		if(s==0) {
			cout<<ans;
			return 0;
		}
	}
	return 0;
}
