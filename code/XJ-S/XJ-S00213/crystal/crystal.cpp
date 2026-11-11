#include <bits/stdc++.h>
using namespace std;
long long mx=-100000000,a[500005];
int main()
{

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	long long ans=0;
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j>=1;j--)
		{
			if(m-a[i]-a[j]>=0)
			{
				m-=a[i]-a[j];
				ans++;
				mx=max(mx,ans);
			}
			else
			{
				break;
			}
		}
	}
	cout<<mx;
	return 0;
}
