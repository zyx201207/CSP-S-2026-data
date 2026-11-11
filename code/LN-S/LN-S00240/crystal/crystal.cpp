#include<bits/stdc++.h>
using namespace std;
int a[5000005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int k=1;
	for(int i=1;i<=n;i++)
	{
		sum+=a[n]-a[1];
		if(sum>m)
		{
			a[n]-=1;
			sum=0;
		}
		else
		{
			a[1]++;
			k++;
		}
	}
	cout<<k+1;
	return 0;
}
