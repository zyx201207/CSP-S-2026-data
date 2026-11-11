#include <bits/stdc++.h>
using namespace std;
int n,m,a[500050],maxx=-1,sum,t;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(a[i]>a[j])
			{
				int p=a[i];
				a[i]=a[j];
				a[j]=a[i];
			}
			
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j>=1;j--)
		{
			if(a[i]-a[j]+t<=m)
			{
				t+=a[i]-a[j];
				sum++;
			}
			else
			{
				break;
			}
		}
		//cout<<sum<<' '<<maxx<<endl;
		maxx=max(sum,maxx);
		t=0;
		sum=0;
	}
	cout<<maxx;
	return 0;
}
