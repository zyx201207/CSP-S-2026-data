#include<bits/stdc++.h>
using namespace std;
const int N=5e5+3;
using LL=long long;
int a[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	LL n,m;
	cin>>n>>m;
	bool fa=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m<=1e10)
	{
		sort(a+1,a+1+n);
		LL ans=0;
		for(int i=2;i<=n;i++)
		{
			LL c=0,s=0;
			for(int j=i;j>=1;j--)
			{
				LL d=a[i]-a[j];
				s+=d;
				if(s<=m)c++;
				else break;
			}
			ans=max(c,ans);
		}
		cout<<ans;
		return 0;
	}
	if(a[1]==a[2])
	{
		cout<<n;
		return 0;
	}
	LL gc=a[2]-a[1];
	LL s=0;
	for(int i=1;i<=1e9;i++)
	{
		LL jhy=i*(i+1)/2;
		jhy*=gc;
		if(jhy>m)
		{
			s=i;
			break;
		}
	}
	cout<<s;
	return 0;
}
