#include<bits/stdc++.h>
using namespace std;
#define int long long
#define io(name) freopen(name".in","r",stdin);freopen(name".out","w",stdout)
int n,m;
int a[500010];
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	io("crystal");
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int nw=0,ans=0;
	int l=1;
	for(int i=1;i<=n;i++)
	{
		nw+=((i-1)-l+1)*(a[i]-a[i-1]);
		while(nw>m)nw-=a[i]-a[l],l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans;
}