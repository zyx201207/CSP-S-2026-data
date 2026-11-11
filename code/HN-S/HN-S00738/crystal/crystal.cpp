#include<bits/stdc++.h>
using namespace std;
long long n,a[500005]= {},ans=0,s[500005],d[500005]= {};
long long m;
int f1(int x,int y)
{
	int mm=0;
	for(int i=x;i<=y;i++)
	mm+=d[i];
	return s[y]-abs((x-1)*mm);
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	if(n>5000)
	{
		int d=a[3]-a[2];
		for(int i=1;i<n;i++)
		{
			s[i]=(a[i]-a[1]+d)*i;
			if(s[i]>=m)
			{
				cout<<i+1;
				return 0;
			}
		}
		if(s[n]<m)
		{
			cout<<n;
			return 0;
		}
	}
	sort(a+1,a+n+1);
	for(int i=2; i<=n; i++)
		d[i]=a[i]-a[i-1],s[i]=d[i]*(i-1)+s[i-1];
	int ans=0;
	if(f1(1,n)<=m)
	{
		cout<<n;
		return 0;
	}
	
	for(int i=1;i<=n-1;i++)
	for(int j=i+1;j<=n;j++)
	{
		if(f1(i,j)<m)
		ans=max(ans,j-i+1);
		while(f1(i,j)==m)
		{
			ans=max(ans,j-i+1);
			j++;
		}
	}
	cout<<ans;
	return 0;
}
