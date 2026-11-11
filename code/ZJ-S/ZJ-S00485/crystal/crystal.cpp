#include <bits/stdc++.h>
using namespace std;
long long a[5000005];
int main()
{
	long long n,m,ans,cnt=1;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}	
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<n;j++)
		{
			if(a[j]>a[j+1])
			{
				swap(a[j],a[j+1]);
			}
		}
	}
	for (int j=1;j<n;j++)
	{
		if (a[j]<a[j+1])
			{
				m-=cnt*(a[j+1]-a[j]);
				cnt+=1;
				ans++;
				if(m<0)break;
			}
	}
	cout<<ans-1;
} 
