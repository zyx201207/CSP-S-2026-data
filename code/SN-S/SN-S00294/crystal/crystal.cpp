#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=0;
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
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		long long cnt=0,mm=m;
		for(int j=i;j>=1;j--)
		{
			if(mm>=a[i]-a[j])
			{
				mm-=(a[i]-a[j]);
				cnt++;
			}
			else
			{
				break;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}

