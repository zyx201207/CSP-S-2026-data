#include<bits/stdc++.h>
using namespace std;
const int mx=2e6+1;
long long n;
char a[200001];
long long m[200001];
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long k=0;
	char b[mx];
	for(int i=1; i<=n; i++) {
		cin>>m[i]>>a[i];
		for(int j=1; j<=m[i]; j++) {
			k+=1;
			b[k]=a[i];
		}
	}
	long long ans=0;
	cout<<k<<endl;
	if(k%2==0) {
		for(int i=1; i<=k/2; i++) {
			if(b[i]==b[k-i+1]) {
			} else {
				ans++;
			}
		}
		cout<<ans;
	} else {
		for(int i=1; i<=k/2; i++) {
			if(b[i]==b[k-i+1]&&i!=(k+1)/2) {
			} else {
				ans++;
			}
		}
		cout<<ans;
	}
}
