#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,ans,a[N],pre[N];
bool cmp(int x,int y) {return x<y;}
bool check(int x,int k) {
	int res=(k-x+1)*a[k]-(pre[k]-pre[x-1]); 
	return res<=m;
}
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+1+n,cmp);
	for(int i=1; i<=n; i++) {
		pre[i]=pre[i-1]+a[i];
		int l=1,r=i;
		while(l<r) {
			int mid=(l+r)>>1;
			if(check(mid,i)) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}