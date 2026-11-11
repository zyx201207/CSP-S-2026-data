#include <bits/stdc++.h>
#define int long long
using namespace std;
#define PID "crystal"
#define FIN freopen(PID".in","r",stdin)
#define FOU freopen(PID".out","w",stdout)
int n,m,l,p,s,k;
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
		if(i<=n-1&&a[i]<a[i+1]){
			k=a[i];
		}
	}
	for(int i=2; i<=n; i++) {
		b[i]=b[i]+a[i];
	}
	if(b[n]<m) {
		cout<<n;
	}
	if(n==1) {
		cout<<1;
	} 
	if(m<k) {
		cout<<0;
	}
	for(int i=2; i<=n; i++) {
		for(int j=i; j<=n; j++) {
			if(m<b[j]-b[i]) {
				p=j-i+1;
				break;
			}
		}
		if(p>s) {
			s=p;
		}
	}
	cout<<s;
return 0;
}
