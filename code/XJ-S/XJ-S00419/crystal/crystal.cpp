#include<bits/stdc++.h>
using namespace std;
long long a[10^12+5];
long long b[10^12+5];
long long s[10^12+5];
long long cnt[10^12+5];
long long q,p;
long long ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>q;
		b[q]=1;
		p=max(p,q);
	}
	int r=1;
	for(int i=1;i<=p;i++)
	{
		if(b[i]==1)
		{
			a[r]=i;
			r++;
		}
	}
	for(int i=1;i<=n-1;i++)
	{
		s[i]=a[i+1]-a[i];
	}
	for(int i=1;i<=n-1;i++)
	{
		for(int j=0;j<=n-i;j++)
		{
			long long int x=0;
			x+=s[i+j]*(j+1);
			if(x>m)
			{
				cnt[i]=j+1;
				break;
			}
		}
	}
	for(int i=1;i<=n-1;i++)
	{
		ans=max(ans,cnt[i]);
	}
	cout<<ans;
	return 0;
}
