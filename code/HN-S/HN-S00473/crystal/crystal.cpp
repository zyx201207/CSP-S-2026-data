#include<bits/stdc++.h>
using namespace std;
long long a[1000001],b[1000001];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,c=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--)
	{
		long long s=0,h=0 ;
		for(int j=i;j>=1;j--)
		{
			s+=a[i]-a[j];
			if(s>m)
			{
				break;
			}
			h++;
		}
		c=max(c,h);
	}
	cout<<c;
	return 0;
 } 
