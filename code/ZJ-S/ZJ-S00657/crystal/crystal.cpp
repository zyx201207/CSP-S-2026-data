#include<bits/stdc++.h>
using namespace std;
long long a[500010];
long long n,m,sum=0,tot=1,ans=1,l=1,r=1;
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
	sort(a+1,a+n+1);
	while(r<n)
	{
		r++;
		if(a[r]==a[r-1])
		{
			tot++;
			ans=max(ans,tot);
			continue;
		}
		else
		{
			sum+=tot*(a[r]-a[r-1]);
			while(sum>m&&l<=n)
			{
				sum-=(a[r]-a[l]);
				l++;
				tot--;
			}
			tot++;
			ans=max(ans,tot);
		}
	}
	cout<<ans;
	return 0;
}
