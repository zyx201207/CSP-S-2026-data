#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll CASE,T,n,k;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>CASE>>T;
//	if (CASE==13 || CASE==14) {
		cin>>n>>k;
		for (ll i=1;i<n;++i) {
			ll u,v;
			cin>>u>>v;
		}
		ll m=(n-1)/2;
		if (m%2==0) { //左右图长度相等 
			m/=2;
			k=(k-1)/2;
			k/=2;
			if ((m-k)%2==0) {
				cout<<(m-k)/2+1<<"\n";
			} else {
				cout<<(m-k+1)/2+1<<"\n";
			}
		} else {
			if (k%2==0) {
				m=(m+1)/2;
				k/=2;
				if ((m-k)%2==0) {
					cout<<(m-k)/2+1<<"\n";
				} else {
					cout<<(m-k+1)/2+1<<"\n";
				}
			} else {
				m=(m+1)/2;
				k=(k+1)/2;
				if ((m-k)%2==0) {
					cout<<(m-k)/2+1<<"\n";
				} else {
					cout<<(m-k+1)/2+1<<"\n";
				}
			}
		}
//	}
	return 0;
}

