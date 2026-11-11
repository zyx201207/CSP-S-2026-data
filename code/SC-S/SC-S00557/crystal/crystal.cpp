#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m, sum=0,ans1=0,ans2=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(i!=0)b[i]=a[i]-b[i-1];
		else b[i]=a[i];
	}
	for(int i=0;i<n;i++)if(b[i]<0)b[i]=0-b[i];
	for(int i=0;i<n;i++)cout<<b[i]<<' ';
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		ans1=0;
		for(int j=i;j<n&&sum+b[j]<=m;j++)
		{
			sum+=b[j];
			ans1++;
		}
		ans2=max(ans1,ans2);
	}
	cout<<ans2;
	return 0;
}