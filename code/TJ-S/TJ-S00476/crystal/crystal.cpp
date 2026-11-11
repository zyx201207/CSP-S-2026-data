#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[500005]={0},sum[500005]={0},m,ans=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n+1);	

	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	
	for(int i=2;i<=n;i++) 
	{
		for(int j=i;j<=n;j++)
		{
			if(i*a[j]-(sum[j]-sum[j-i])<=m)
			{
				ans=i;
				break;
			}
		}
	}
	cout<<ans;
	
	return 0;
}
