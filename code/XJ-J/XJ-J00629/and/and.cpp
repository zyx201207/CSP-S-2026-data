#include<bits/stdc++.h>
using namespace std;
int a[200005];
string cnt[200005];
int c[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m,max=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==n)
	{
		max=a[1]&a[2];
		for(int i=3;i<=n;i++)
		{
			max=max&a[i];
		}
	}
	else if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]>max)
			{
				max=a[i];
			}
		}
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if((a[i]&a[j])>max)
				{
					max=a[i]&a[j];
				}
			}
		}
	}	
	else if(m==3)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					if((a[i]&a[j]&a[k])>max)
					{
						max=a[i]&a[j]&a[k];
					}
				}
			}
		}
	}
	else
	{
		sort(a+1,a+n+1,greater<int>());
		max=a[1];
	}
	cout<<max;
	return 0;
}