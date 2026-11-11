#include<bits/stdc++.h>
#define int long long
using namespace std;
int x,m,n,a[500005],b[500005];
int f=0;
bool cmp(int a,int b)
{
	return a-x<b-x;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		if(i>1)
		{
			if(f==0)f=a[i]-a[i-1];
			else if(a[i]-a[i-1]!=f)f=-1;
		}
	}
	if(f!=-1)
	{
		for(int i=1;i<=n;i++)
		{
			b[i]=i*(i+1)/2*f;
			if(b[i]<0||b[i]<b[i-1])b[i]=LONG_LONG_MAX;
		}
		int x=upper_bound(b+1,b+1+n,m)-b;
		cout<<min(x,n);
	}
	else
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			x=a[i];
			sort(a+1,a+i,cmp);
			int num=0,sum=0;
			for(int j=1;j<=i;j++)
			{
				if(num+a[i]-a[j]<=m)
				{
					num+=a[i]-a[j];
					sum++;
				}
			}
			ans=max(ans,sum);
		}
		cout<<ans;
	}
	
	return 0;
} 
