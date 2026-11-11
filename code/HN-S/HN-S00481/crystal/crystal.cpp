#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N],cnt,ans,st,sum;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	st=1;
	a[0]=a[1];
	for(int i=1;i<=n;i++)
	{
		sum+=(i-st)*(a[i]-a[i-1]);
		while(sum>m)
		{
			sum-=(a[i]-a[st]);
			st++;
		}
		ans=max(ans,i-st+1);
	}
	cout<<ans;
	return 0;
}
