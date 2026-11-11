#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500009],b[500009],js=0,ok=0,ans1=0,ans=0;
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
		if(a[i]!=a[i-1])
		{
		    js++;
			b[js]=i;
		}
	}
	b[js+1]=n;
	for(int i=2,j=1;i<=js;i++)
	{
		ans1+=(a[b[i]]-a[b[i-1]])*(b[i]-b[j]);
		for(;;)
		{
			if(ans1>m)
			{
				ans1-=(a[b[i]]-a[b[j]])*(b[j+1]-b[j]);
				ok=1;
				j++;
			}
			else break;
		}
		long long k=m-ans1,ew=0;
		if(ok==1)ew=(k-k%(a[b[i]]-a[b[j-1]]))/(a[b[i]]-a[b[j-1]]);
		ans=max(ans,ew+b[i+1]-b[j]);
	}
	cout<<ans;
}
