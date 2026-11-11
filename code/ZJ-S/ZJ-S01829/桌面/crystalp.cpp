#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500001],s[500001],n,m,ans;
int al,ar;
signed main()
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	//cout.tie(0);
	//freopen("crystal4.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int tmp=0,l=i;
		while(tmp<=m && l>=1)
		{
			tmp+=(a[i]-a[l]);
			l--;
		}	
		cout<<l+1<<" "<<i<<'\n';
		if(i-l>ans)
			ans=i-l;
	}	
	cout<<ans<<'\n';
}
