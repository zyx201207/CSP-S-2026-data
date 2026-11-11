#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200010];
char c[200010];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ll n,cnt=0,flag;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	ll l=1,r=n;
	while(l<=r) {
		flag=0;
		if(c[l]==c[r]) flag=1; 
		if(a[l]>a[r]) {
			if(!flag) cnt+=a[r];
			a[l]-=a[r];
			r--;
			continue;
		}
		if(a[r]>a[l]) {
			if(!flag) cnt+=a[l];
			a[r]-=a[l];
			l++;
			continue;
		}
		if(a[l]==a[r]) {
			if(!flag) cnt+=a[r];
			l++,r--;
			continue;
		}
	}
	cout<<cnt;
	return 0;
}

