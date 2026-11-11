#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll N=5e5+12;
ll n,m,a[N],sum[N];
ll l[N],r[N],cnt;

int main() {
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>m;
	for(ll i=1;i<=n;++i) {
		cin>>a[i];
	}
	
	if(n==1) {
		cout<<1<<'\n';
		return 0;
	}
	
	sort(a+1,a+1+n);
	
	for(ll i=1;i<=n;++i) {
		
		sum[i]=sum[i-1]+a[i];
		
		if(a[i]!=a[i-1]||i==1) {
			cnt++;
			l[cnt]=r[cnt]=i;
		} else r[cnt]=i;
		
	}
	
	ll ans=0;
	for(ll i=1;i<=cnt;++i) {
		
		ll L=1,R=r[i],mid;
		while(L<R) 
		{
			mid=(L+R)>>1;
			if(a[r[i]]*(r[i]-mid+1)-(sum[r[i]]-sum[mid-1])<=m) R=mid;
			else L=mid+1;
		}
		
		ans=max(ans,r[i]-R+1);
		
	}
	
	cout<<ans<<'\n';
	
	return 0;
	
}

/*

5 5
1 2 4 8 9

3


5 8
-3 -1 2 2 7

4

*/