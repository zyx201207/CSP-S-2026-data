#include <bits/stdc++.h>
#define int long long
using namespace std;
#define PID "hub"
#define FIN freopen(PID".in","r",stdin)
#define FOU freopen(PID".out","w",stdout)
int n,m,l,k,p,s;
int a[100010],b[100010];
signed main() {
	FIN;
	FOU;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; ++i) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n; i>=2; --i) {
		a[i]-=a[i-1];
	}
	bool f=0;
	for(int i=2; i<=n; i++) {
		b[i]=b[i]+a[i];
		f=1;
		if(m<b[i]&&l==0) {
			l=i;
		}
	}
	if(l==0) {
		if(f==1) {
			cout<<n;
		} else {
			if(n==1) {
				cout<<1;
			} else {
				cout<<0;
			}
		}
	} else {
		for(int i=2; i<=n; i++) {
			for(int j=i; j<=n; j++) {
				if(m<b[j]-b[i]-1) {
					p=j-i+1;
					break;
				}
			}
			if(p>s) {
				s=p;
			}
		}
		cout<<s;
	}
	return 0;
}
