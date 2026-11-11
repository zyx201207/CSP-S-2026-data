#include<bits/stdc++.h>
using namespace std;
long long a[500050];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,ans2=0;
	long long m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];		
	}
	sort(a+1,a+n+1);
	int l=1,r=1;
	while(l<=n&&r<=n)
	{
		if(ans<=m)
		{			
			ans=ans+(r-l)*(a[r]-a[r-1]);
			if(ans<=m)
				ans2=max(ans2,r-l+1);
			r++;
		}
		else
		{			
			ans=ans-(a[r]-a[l]);
			l++;
		}
	}	
	cout<<ans2;
	return 0;
}