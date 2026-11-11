#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int a[N]/*,s=0*/;
char c[N];
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n,ans=0,cnt=0;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>c[i];
//		s+=a[i];
	}
	int l=0,r=n+1,/*lft=1,rght=n,*/lt=0,rt=0/*,mid=(n+1)>>1*/;
//	cout<<s<<'\n';
	while(l<=r) {
//		cout<<c[l]<<' '<<c[r]<<' '<<l<<' '<<r<<' '<<cnt<<'\n';
//		if(l>=r)break;
//		if(a[l]==0)l++;
//		if(a[r]==0)r--;
		if(c[l]==c[r]) {
			if(a[l]-lt>a[r]-rt) {
				cnt+=2*(a[r]-rt);
				lt+=a[r]-rt,rt=0;
				r--;
			} else if(a[l]-lt<a[r]-rt) {
				cnt+=2*(a[l]-lt);
				rt+=a[l]-lt,lt=0;
				l++;
			} else {
				cnt+=2*(a[r]-rt);
				lt=0,rt=0;
				l++,r--;
			}
		} else {
			if(a[l]-lt>a[r]-rt) {
				cnt+=2*(a[r]-rt),ans+=(a[r]-rt);
				lt+=a[r]-rt,rt=0;
				r--;
//				cout<<l<<' '<<r<<'\n';
			} else if(a[l]-lt<a[r]-rt) {
				cnt+=2*(a[l]-lt),ans+=(a[l]-lt);
				rt+=a[l]-lt,lt=0;
				l++;
//				cout<<l<<' '<<r<<'\n';
			} else {
				cnt+=2*(a[r]-rt),ans+=(a[r]-rt);
				lt=0,rt=0;
				l++,r--;
//				cout<<l<<' '<<r<<' '<<ans<<'\n';
			}
		}
	}
	cout<<ans;
	return 0;
}
