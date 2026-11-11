#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;long long sum=0;long long cnt=0;
	long long m,max=0,mid;
	cin>>n>>m;
	int num[n+1]={0};
	for(int i=0;i<=n-1;i++)
	{
		cin>>num[i];
		max+=num[i];
	}
	mid=max/n;
	int a[n+1]={0};
	for(int i=0;i<=n-1;i++)
	{
		a[i]=abs(mid-num[i]);
	}
	for(int i=0;i<=n-2;i++)
	{
		for(int j=i+1;j<=n-1;j++)
		{
			if(a[j]<a[i])
			{
				int s;s=a[j];a[j]=a[i];a[i]=s;
			}
		}
	}	
	for(int i=0;i<=n-1;i++)
	{
		sum+=a[i];
		if(sum>m)
		{
			sum=sum-a[i];
			break;
		}
		cnt++;
	}
	cout<<cnt;
	return 0;
}
