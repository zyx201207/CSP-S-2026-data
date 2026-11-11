#include<bits/stdc++.h> 
using namespace std;
long long n,m,a[500005],ans,last;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(n>5000)
	{
		m/=(a[2]-a[1]);
		m*=2;
		int k=sqrt(m);
		if(k*(k+1)<=m)
			k+=2;
		else
			k++;
		ans=k;
		for(long long l=1,r=1;r<=5000;)
		{
			if(last<=m)
			{
				ans=max(ans,l-r+1);
				r++;
				last+=(r-l)*(a[r]-a[r-1]);
			}
			else
			{
				l++;
				last-=a[r]-a[l-1]; 
			}
		}
		cout<<ans;
		return 0;
	}
	for(long long l=1,r=1;r<=n;)
	{
		if(last<=m)
		{
			ans=max(ans,r-l+1);
			r++;
			last+=(r-l)*(a[r]-a[r-1]);
		}
		else
		{
			l++;
			last-=a[r]-a[l-1]; 
		}
	}
	cout<<ans;
	return 0;
}
