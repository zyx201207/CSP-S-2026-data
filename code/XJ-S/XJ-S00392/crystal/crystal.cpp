#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int m,a[N],sum=0;
int n,ans=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-1;i++)
	{
		sum=0;
		for(int j=1;j<=n-i;j++)
		{
			sum+=a[n-i+1];
			sum-=a[n-j-i+1]; 
			if(m>=sum)
			{
				if(j+1>ans)
				{
					ans=j+1;
				} 
			}
			else
			{
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
