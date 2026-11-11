#include<bits/stdc++.h>
using namespace std;
int a[200005],b[31],c[31];
int n,m,ans,v;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	ans=a[1];
	if(m==1)
	{
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(m==n)
	{
		for(int i=2;i<=n;i++)
		{
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2)
	{
		ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				v=a[i]&a[j];
				ans=max(ans,v);
			}
		}
		cout<<ans;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
//Trick||Treat!
