#include<bits/stdc++.h>
using namespace std;
const long long MAXN=2e5+5;
long long n;
long long a[MAXN];
char c[MAXN];
long long ans=0;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1; i<=n; i++) {
		cin>>a[i]>>c[i];
	}
	for(long long i=1,j=n; i<=j&&i<=n&&j>=1;) {
		if(c[i]!=c[j]) {
			if(a[i]>a[j]) {
				a[i]-=a[j];
				ans+=a[j];
				j--;
				continue;
			} else if(a[i]<a[j]) {
				a[j]-=a[i];
				ans+=a[i];
				i++;
				continue;
			} else if(a[i]==a[j]) {
				ans+=a[i];
				i++;
				j--;
				continue;
			}
		} else {
			if(a[i]>a[j]) {
				a[i]-=a[j];
				j--;
				continue;
			} else if(a[i]<a[j]) {
				a[j]-=a[i];
				i++;
				continue;
			} else if(a[i]==a[j]) {
				i++;
				j--;
				continue;
			}
		}
	}
	cout<<ans;
	return 0;
}
