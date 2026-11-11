#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
int a[1000005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<=m;j++)
		{
			ans=a[i]&a[i-1];
			if(m>2)
			{
				ans=ans&a[i-j+1];
			}
		}
	cout<<ans;
	break;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
