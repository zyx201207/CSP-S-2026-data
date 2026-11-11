#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
int n;
struct Node {
	string s;
	ll num;
};
Node a[N];

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i].num>>a[i].s;
	}
	
	ll l=0,r=n+1,cntl=0,cntr=0, ans=0;
	while(l+1<r) {
		if(cntl<cntr) {
			l++;
			if(a[l].s!=a[r].s)
				ans+=min(a[l].num ,(cntr-cntl));
			cntl+=a[l].num;
		}
		if(cntr<cntl) {
			r--;
			if(a[l].s!=a[r].s)
				ans+=min(a[r].num, (cntl-cntr));
			cntr+=a[r].num;
		}
		if(cntl==cntr) {
			l++,r--;
			cntl+=a[l].num;
			cntr+=a[r].num;
			if(a[l].s!=a[r].s)
				ans+=min(a[l].num,a[r].num);
		}
	}
	cout<<ans<<endl;
	return 0;
}
