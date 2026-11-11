#include <bits/stdc++.h>
using namespace std;
int n,x[200010],l,r;
char c[200010];
long long ans;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>x[i]>>c[i];
	l=1; r=n;
	while(true) {
		if(l>=r) break;
		if(c[l]!=c[r]) {
			if(x[l]==x[r]) {
				ans=ans+x[l];
				l++;
				r--;
			}
			else if(x[l]>x[r]) {
				ans=ans+x[r];
				x[l]=x[l]-x[r];
				r--;
			}
			else if(x[l]<x[r]) {
				ans=ans+x[l];
				x[r]=x[r]-x[l];
				l++;
			}
		}
		else {
			if(x[l]==x[r]) {
				l++;
				r--;
			}
			else if(x[l]>x[r]) {
				x[l]=x[l]-x[r];
				r--;
			}
			else if(x[l]<x[r]) {
				x[r]=x[r]-x[l];
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
