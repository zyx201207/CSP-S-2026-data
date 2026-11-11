#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	long long a[500005],num=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
	{
		a[i]=a[i+1]-a[i];
	}
	for(int i=1;i<n;i++)
	{
		if(m>=a[i]*i)
		{
			num++;
		}
		else
		{
			for(int j=i;j<=n;j++)
			{
				if(a[j]==a[i])
				num++;
			    else
			    {
					break;
				}
			}
			break;
		}
	}
	cout<<num;
	return 0;
}
