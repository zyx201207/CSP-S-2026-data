#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int ans=-1;
int ans2=-1;
int an(int x,int y)
{
	bool w[30],d[30];
	int q=1073741824;
	for(int i=30;i>=1;i--)
	{
		if(x>=q)
		{
			x-=q;
			w[i]=1;
		}
		else w[i]=0;
		q/=2;
	}
	q=1073741824;
	for(int i=30;i>=1;i--)
	{
		if(y>=q)
		{
			y-=q;
			d[i]=1;
		}
		else d[i]=0;
		q/=2;
	}
	bool s[30];
	int ans2222=0;
	for(int i=1;i<=30;i++)
	{
		s[i]=w[i]and d[i];
	}
	int j=1;
	for(int i=1;i<=30;i++)
	{
		if(s[i]==1) ans2222+=j;
		j*=2;
	}
	return ans2222;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans=max(ans,a[i]);
	}
	if(m==1)
	{
		cout<<ans;
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				ans2=max(ans2,an(i,j));
			}
		}
		cout<<ans2;
		return 0;
	}
	return 0;
}
