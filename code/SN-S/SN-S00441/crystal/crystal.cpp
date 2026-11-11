// 门可铭 辅轮中学 SN-S00441
#include <bits/stdc++.h>
using namespace std;
int n,maxx;
long long m,a[500010];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=1;
	while(r<n)
	{
		r++;
		m-=(r-l)*(a[r]-a[r-1]);
		while(m<0&&l<r) m+=a[r]-a[l],l++;
		maxx=max(maxx,(r-l+1));
	}
	cout<<maxx;
	return;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}
