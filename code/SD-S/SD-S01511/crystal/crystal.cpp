#include<bits/stdc++.h>
using namespace std;
long long a[500010],p[500010],s1[500010];
long long a1=1e13;
int a2,ans,aa;
int q;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==a[1])q++;
	}
	if(q==n)cout<<n;
	else
	{
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=i;j++)
			{
				if(a[i]-a[j]>0)
					p[i]+=(a[i]-a[j]);
			}
		}
		for(int i=1;i<=n;i++)
		{
			ans=0;
			for(int j=i-1;j>=1;j--)
			{
				if(ans<=m)ans+=(a[i]-a[j]),aa=max(aa,i-j+1);
				else break;
			}
		}
		cout<<aa;
	}
	return 0;
}
