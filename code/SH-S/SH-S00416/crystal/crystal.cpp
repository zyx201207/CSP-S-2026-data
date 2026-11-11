#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500010],ans;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1); 
	for(int i=n;i>=2;i--)
	{
		int lm=m,lans=0;
		for(int j=i;j>=1;j--)
		{
			lm-=(a[i]-a[j]);
			if(lm<0)
			{
				break;
			}
			lans++;
		}
		ans=max(ans,lans);
	}
	cout<<ans;
	return 0;
}
  
