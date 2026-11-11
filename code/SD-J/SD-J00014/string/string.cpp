#include<bits/stdc++.h>
using namespace std;
struct x {
	int a;
	char b;
} k[200005];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>k[i].a>>k[i].b;
	}
	int l=1,r=n;
	long long ans=0;
	while(l<r) {
		if(k[l].a<k[r].a) {
			k[r].a-=k[l].a;
			if(k[l].b!=k[r].b) {
				ans+=k[l].a;
			}
			k[l].a=0;
			l++;
		} else if(k[l].a>k[r].a) {
			k[l].a-=k[r].a;
			if(k[l].b!=k[r].b) {
				ans+=k[r].a;
			}
			k[r].a=0;
			r--;
		} else {
			if(k[l].b!=k[r].b) {
				ans+=k[l].a;
			}
			k[l].a=0;
			l++;
			k[r].a=0;
			r--;
		}
	}
	cout<<ans;
	return 0;
}
