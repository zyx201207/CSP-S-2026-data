#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long p[200005];
long long n;
long long ans;
char ch;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(long long i=1; i<=n; i++) {
		cin>>a[i]>>ch;
		p[i]=(ch-'a');
	}
	long long l=1,r=n;
	while(l<=r) {
		if(a[l]>=a[r]) {
			a[l]-=a[r];
			if(p[l]!=p[r]) {
				ans+=a[r];
			}
			r--;
		} else if(a[r]>=a[l]) {
			a[r]-=a[l];
			if(p[l]!=p[r]) {
				ans+=a[l];
			}
			l++;
		}
	}
	cout<<ans;

	return 0;
}

