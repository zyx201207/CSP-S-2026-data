#include <bits/stdc++.h>
#define int long long
using namespace std;
#define PID "migrate"
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
		p=l-2;
		s=2;
		for(int i=2; i<=n; i++) {
			if((n+1-i)*b[i]>b[i+p]-b[i+p-1]) {
				if(p+2<n){
					p++;
				}
				else {
					p=n;
					break;
				}
			}
		}
		for(int i=s; i<=n; i++) {
            if(b[p]-b[i]>=m){
            	cout<<p-i;
            	break;
			}
		}

	}
	return 0;
}
