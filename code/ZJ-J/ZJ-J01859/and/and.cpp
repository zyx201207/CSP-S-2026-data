#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005],ans,b[50],sum[200005];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	sum[0]=(1<<32);
	for(int i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]&a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		int c[50],tot=0,now=a[i];
		while(now)
		{
			c[++tot]=now%2;
			now/=2;
		}
		for(int j=1;j<=tot;j++) if(c[j]) b[j]++;
	}
	int x;
	for(x=0;x<=35;x++) if((1<<x)>a[n]) break;
	int y=-1;
	for(int i=x;i>=1;i--)
	{
		if(b[i]>=m)
		{
			y=i;
			break;
		}
	}
	if(y==-1)
	{
		cout<<"0\n";
		return 0;
	}
	int l,r;
	for(int i=n;i>=1;i--)
	{
		if(a[i]<(1<<y))
		{
			r=i;
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=(1<<(y-1)))
		{
			l=i;
			break;
		}
	}
	for(int i=l;i<=r-m+1;i++)
	{
		int now=a[i];
		for(int j=i+1;j<=i+m-1;j++)
			now=now&a[j];
		ans=max(ans,now);
	}
	cout<<ans<<"\n";
	return 0;
}