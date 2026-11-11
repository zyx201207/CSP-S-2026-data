#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500020],lj,ls;
int ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(n==1)
	{
		cout<<"1";
		return 0;
	}
	sort(a,a+n);
	lj=n-1;
	for(int i=n-1;i>=0;i--)
	{
		long long s=0;
		if(i!=n-1)
		{
			s=ls-(a[i+1]-a[i])*(i-lj+1);
		}
		bool flag=0;
		for(int j=lj-1;j>=0;j--)
		{
			if(m<s)
			{
				ans=max(ans,(i-j-1));
				flag=1;
				lj=j+1;
				ls=s;
				break;
			}
			s+=(a[i]-a[j]);
		}
		if(m<=s&&flag==0)
		{
			ans=max(ans,(i+1));
			cout<<ans;
			return 0;
		}
	}
	cout<<ans;
	return 0;
}
