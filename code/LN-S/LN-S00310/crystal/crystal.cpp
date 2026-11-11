#include<bits/stdc++.h>
using namespace std;
long long a[500009],m,ans=1,maxn=1;
int n;
void flag(int t)
{
	long long sum=m;
	while(sum--)
	{
		sort(a+t,a+n+1);
		a[t]++;
		for(int i=t+1;i<=n;i++)
		{
			if(a[i]==a[i-1]) ans++;
			else 
			{
				if(ans>maxn) maxn=ans;
				ans=1;
			}
		}
	}
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int t=1;t<=n;t++)
	{
		flag(t);
	}
	cout<<maxn;
	return 0;
}
