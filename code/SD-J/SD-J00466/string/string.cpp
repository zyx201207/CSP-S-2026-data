#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int a[N];
char c[N];
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;
	int Max=0;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>c[i];
		Max=max(Max,a[i]);
	}
	if(n==1) {
		cout<<0;
		return 0;
	}
	if(Max==1){
		int l=1,r=n,cnt=0;
		while(l<=r){
			if(c[l]!=c[r]){
				cnt++;
			}
			l++,r--;
		}
		cout<<cnt;
		return 0;
	}
	if(n==2){
		cout<<min(a[1],a[2]);
		return 0;
	}
	int l=1,r=n,cnt=0;
	while(l<=r) {
		if(c[l]==c[r]) {
			l++,r--;
			continue;
		}
		if(a[l]>=a[r]) {
			cnt+=a[r];
			a[l]-=a[r];
			r--;
		} else {
			cnt+=a[l];
			a[r]-=a[l];
			l++;
		}
	}
//	for(int i=1; i<=n; i++) cout<<a[i]<<' ';
//	cout<<'\n';
//	cout<<l<<' '<<r;
//	cout<<'\n';
	cout<<cnt;
	return 0;
}
