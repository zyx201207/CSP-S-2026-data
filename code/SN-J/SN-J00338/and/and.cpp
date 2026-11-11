#include <bits/stdc++.h>
using namespace std;
int n,m;
int s[200015];
int ans;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=0;i<n;i++) {
		cin>>s[i];
	}
	sort(s,s+n);
	if (m==1) {
		cout<<s[n-1];
		return 0;	
	}
	if (m==2) {
		int k[200015] = {0};
		bool f = 0;
		for (int i=0;i<n;i++) {
			for (int j=0;j<n;j++) {
				if (i!=j) {
					if (s[i]==s[j]) {
						k[i] = s[i];
						f = 1;	
					}
				}
			}
		}
		sort(k,k+n);
		if (f==1) {
			cout<<k[n-1];
		}
		else {
			cout<< (s[n-1] & s[n-2]);
		}
		return 0;
	}
	if (m==n) {
		ans = s[0];
		for (int i=1;i<n;i++) {
			ans=(ans&s[i]);	
		}
		cout<<ans;
	}
	return 0;
}

