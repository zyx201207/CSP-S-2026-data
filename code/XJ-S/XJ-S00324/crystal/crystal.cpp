#include <bits/stdc++.h>
using namespace std;
long long a[500005],c[500005],s[500005],f[500005],cnt,tot,n,m,ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++) c[i]=a[i+1]-a[i];
	f[1]=1;
	for(i=1;i<=n;i++)
	{
		cnt++;
		tot+=c[i]*cnt;
		while(tot>m)
		{
			tot=tot-(a[i+1]-a[i-cnt])-c[i-cnt+1];cnt--; 
		}
		f[i+1]=cnt+1;
	}
	//for(i=1;i<=n;i++) cout<<f[i]<<" ";
	for(i=1;i<=n;i++)
	{
		ans=max(ans,f[i]);
	}
	cout<<ans;
	return 0;
} 
