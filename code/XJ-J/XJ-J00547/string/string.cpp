#include <iostream>
using namespace std;
int max(int x, int y)
{
	if(x>y)
	{
		return x;
	}
	else
	{
		return y;
	}
	return x;
}
int min(int x,int y)
{
	if(x>y)
	{
		return y;
	}
	else
	{
		return x;
	}
	return x;
}
int main()
{
	freopen("string.in","m",stdin);
	freopen("string.out","r",stdout);
	int n,m=0;
	cin>>n;
	int a[n+1];
	char b[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		m+=a[i];
	}
	int u=1;
	int ans=0;
	int y=0,t=0;
	while(!(u==n+1 || u+1==n+1))
	{
		if(t!=0)
		{
			if(b[u]==b[u-1])
			{
				if(max(a[u-1],a[n+1+1])==a[u-1])
				{
					a[u]+=y;
				}
			}
			if(b[n+1]==b[n+1+1])
			{
				if(max(a[u-1],a[n+1+1])==a[n+1+1])
				{
					a[n+1]+=y;
				}
			}
		}
		if(b[u]==b[n+1] && a[u]==a[n+1])
		{
			u++;
			n--;
			t--;
			continue;
		}
		else
		{
			ans+=min(a[u],a[n+1]);
			y=max(a[u],a[n+1])-min(a[u],a[n+1]);
		}
		t--;
	}
	cout<<ans;
	return 0;
}