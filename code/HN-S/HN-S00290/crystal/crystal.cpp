#include<bits/stdc++.h>
using namespace std;
long long ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long max=m;
	long long a[100];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	long long s=0;
	s=(1+n)/2-1;
		if(a[s-1]!=a[s])
		{
			max=max-s+a[s-1];
			ans++;
		}
		if(a[s-2]!=a[s])
		{
			max=max-s+a[s-2];
			ans++;
		}
		if(a[s+1]==a[s])
			ans++;
	ans+=1;
	cout<<ans;
	return 0;
} 
