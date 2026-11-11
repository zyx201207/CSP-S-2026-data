#include<bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
using namespace std;
typedef long long ll;
const ll N=2e5+10;
ll n,m;
struct node {
	ll v;
} a[N];
bool f[N];
bool cmp(node a,node b) {
	return a.v>b.v;
}
signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i].v;
	}
	sort(a+1,a+n+1,cmp);
	if(m==1) {
		cout<<a[1].v;
		return 0;
	}
	if(m==n) {
		ll ans=a[1].v;
		for(int i=2; i<=n; i++)
			ans=(ans & a[i].v);
		cout<<ans;
		return 0;
	} else {
		bool flag=0;
		for(int i=1; i<=n; i++) {
			if(a[i].v!=pow(2,log2(a[i].v+1))-1) {
				flag=1;
				break;
			}
		}
		if(flag==0) {
			ll ans=a[1].v;
			m--;
			for(int i=2; i<=n && m>0; i++)
				ans=(ans & a[i].v),m--;
			cout<<ans;
			return 0;
		}
	}
	ll mx=INT_MIN;
	ll pos1=0,pos2=0;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(i!=j) {
				if(mx<(a[i].v & a[j].v)) {
					mx=(a[i].v & a[j].v);
					pos1=i;
					pos2=j;
				}
			}
		}
	}
	f[pos1]=1,f[pos2]=1;
	m-=2;
	while(m--) {
		ll k=0,pos=0;
		for(int i=1; i<=n; i++) {
			if(f[i]==0) {
				k=i;
				break;
			}
		}
		ll maxn=(mx & a[k].v);
		for(int i=1; i<=n; i++) {
			if(f[i]==1) continue;
			if(i!=k) {
				if(maxn<(mx & a[i].v)) {
					maxn=mx & a[i].v;
					pos=i;
				}
			}
		}
		mx=maxn;
		f[pos]=1;
	}
	cout<<mx;
	return 0;
}
/*



*/
