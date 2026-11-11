#include<bits/stdc++.h>
using namespace std;

long long n;
const long long N=2e5;
long long a[N+5];
string s[N+5];
long long ans=0;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1; i<=n; i++) {
		cin>>a[i]>>s[i];
		s[i]=" "+s[i];
	}
	long long l=1,r=n;
	while(l<=r) {
		if(a[l]==a[r]) {
			if(s[l]!=s[r]) ans+=a[l];
			l++;
			r--;
		} else {
			if(a[l]>a[r]) {
				if(s[l]==s[r]) a[l]-=a[r];
				else {
					ans+=a[r];
					a[l]-=a[r];
				}
				r--;
			} else {
				if(s[l]==s[r]) a[r]-=a[l];
				else {
					ans+=a[l];
					a[r]-=a[l];
				}
				l++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
