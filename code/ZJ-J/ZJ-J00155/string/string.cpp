#include <bits/stdc++.h>
using namespace std;
int n,a[200000],ans;
string s;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0; i<n; i++) cin>>a[i]>>s[i];
	int l=0,r=n-1;
	while(l<r) {
		if(s[l]!=s[r]) ans+=min(a[l],a[r]);
		if(a[l]>=a[r]) a[l]-=a[r],a[r--]=0;
		else a[r]-=a[l],a[l++]=0;
	}
	cout<<ans;
	return 0;
}