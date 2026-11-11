#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll MAXN=5e5+7;
ll n;
ll m,ani[MAXN];
ll delta[13005][13005],sum[MAXN],res,ans;

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1; i<=n; i++) {
		cin>>ani[i];
	}
	sort(ani+1,ani+n+1);
	for(ll i=1; i<n; i++) {
		for(ll j=2; j<=n; j++) {
			delta[i][j]=ani[j]-ani[i];
		}
	}
	for(ll i=1; i<n; i++) {
		for(ll j=2; j<=n; j++) {
			if(delta[i][j]>=0)
				sum[j]+=delta[i][j];
		}
	}
	for(int j=2; j<=n; j++) {
		if(sum[j]<=m&&sum[j]>res) {
			res=j;
		}
	}
	for(int i=1; i<n; i++) {
		if(delta[i][res]>=0) {
			++ans;
		}
	}
	cout<<ans<<'\n';
	return 0;
}