#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int i,j;
	long long n,m;
	long long sum=0,cnt=0,ans=0,ansi=1;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		sum=0;
		for(j=1;j<=i;j++)
		{
			sum=sum+(a[i]-a[j]);
		} 
		if(sum<=m)
		{
			cnt=i;
			ans=a[i];
		}
		else if(sum>m) break;
	}
	for(i=cnt;i<=n;i++)
	{
		if(a[i]==ans) ansi=i;
		else if(a[i]>ans)break;
	}
	cout<<ansi;
	return 0; 
}
