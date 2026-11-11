#include <bits/stdc++.h>
using namespace std;
bool r=1;
long long cha;
long long a[500005],b[500005],ans,n,m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	long long ans1=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cha=a[2]-a[1];
	for(int i=2;i<=n;i++)
	{
		long long oldcha=cha;
		cha=a[i]-a[i-1];
		if(oldcha!=cha)
		{
			r=0;
			break;
		}
	}
	if(r==1)
	{
		long long anss=0;
		while(1)
		{
			anss++;
			m-=anss*cha;
			if(anss==n||m<=0)
				break;
		}
		cout<<anss;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		ans1=0;
		memset(b,0,sizeof(b));
		for(int j=1;j<=i;j++)
		{
			b[j]=a[i]-a[j];
		}
		sort(b+1,b+i+1);
		int qq=m;
		while(1)
		{
			ans1++;
			qq-=b[ans1];
			if(ans1==i||qq<=0)
			{
				break;
			}
		}
		ans=max(ans,ans1);
	}
	cout<<ans;
	return 0;
 } 
