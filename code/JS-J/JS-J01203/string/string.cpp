#include<bits/stdc++.h>
using namespace std;
int n;
long long ans=0;
pair<int,char> a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].first>>a[i].second;
	}
	if(n==1) cout<<0;
	else
	{
		for(int i=1;i*2<=n;i++)
		{
			if(a[i].second!=a[n-i+1].second)
			{
				if(a[i].first>a[n-i+1].second)
				{
					ans+=a[n-i+1].first;
				}
				else
				{
					ans+=a[i].first;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
