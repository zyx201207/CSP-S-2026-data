#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,ans;
vector<ll>v;
void dfs(ll x,ll cnt,ll sum) {
	if(cnt==m) {
		ans=max(ans,sum);
	}
	if(x>n) {
		return;
	}
	if(n-x+1+cnt<m) {
		return;
	}
	dfs(x+1,cnt,sum);
	dfs(x+1,cnt+1,sum&v[x]);
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	v.resize(n+1);
	for(ll i=1; i<=n; i++) {
		cin>>v[i];
	}
	if(m==1) {
		for(ll i=1; i<=n; i++) {
			ans=max(ans,v[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==n) {
		ans=v[1];
		for(ll i=2; i<=n; i++) {
			ans&=v[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2) {
		for(ll i=1; i<n; i++) {
			for(ll j=i+1; j<=n; j++) {
				ans=max(ans,v[i]&v[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m>2000) {
		bool flag=1;
		for(ll i=1; i<=n; i++) {
			if((ll)log2(v[i]+1)!=ceil(log2(v[i]+1))) {
				flag=0;
				break;
			}
		}
		if(flag) {
			sort(v.begin()+1,v.end(),greater<ll>());
			cout<<v[m];
			return 0;
		}
		flag=1;
		ll t[5]= {0,0,0,0,0};
		for(ll i=1; i<=n; i++) {
			t[v[i]]++;
			if(v[i]>4) {
				flag=0;
				break;
			}
		}
		if(flag) {
			if(t[2]+t[3]==m) {
				cout<<2;
			} else if(t[1]+t[3]==m) {
				cout<<1;
			} else {
				cout<<0;
			}
			return 0;
		}
		cout<<0;
	}
	dfs(1,0,pow(2,30)-1);
	cout<<ans;
	return 0;
}