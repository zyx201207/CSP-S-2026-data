#include<bits/stdc++.h>
#define N 500005
#define int long long
using namespace std;
int a[N];
int pre[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) {
		pre[i]=pre[i-1]+a[i];
	}
	int l=1;
	int ans=0;
	for(int r=1;r<=n;r++) {
		while(l<r && a[r]*(r-l+1)-(pre[r]-pre[l-1])>m) l++;
		ans=max(ans,r-l+1);
	}
	cout<<ans<<'\n';
	return 0;
}