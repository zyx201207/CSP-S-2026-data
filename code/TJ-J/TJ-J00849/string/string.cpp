#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a,l,r;
	int n;
	cin>>n;
	int cc=0;
	long long ans=0;
	for(int i=0; i<n; i++) {
		int k;
		string k1;
		cin>>k>>k1;
		cc+=k;
		for(int i=0; i<k; i++) a+=k1;
	}
	bool f=n%2;
	cc=cc/2;
	for(int i=0; i<cc; i++) {
		l+=a[i];
	}
	if(f) {
		for(int i=a.size(); i>cc; i--) r+=a[i];
	} else for(int i=a.size(); i>=cc; i--) r+=a[i];
	for(int i=0; i<cc; i++) {
		if(l[i]!=r[i+1]) ans++;
	}
	cout<<ans;
}
