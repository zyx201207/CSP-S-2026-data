#include<bits/stdc++.h> 
using namespace std;
int n,m,a[500005],p,sum,maxx,ans;
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
		ans=0;
		p=i-1;
		sum=m;
		while(p && sum>0)
		{
			if(a[i]-a[p]<=sum)
			{
				ans++;
				
			}
			sum-=(a[i]-a[p]);
			p--;
			
		}
		maxx=max(ans,maxx);
	}
	cout<<maxx+1;
}
