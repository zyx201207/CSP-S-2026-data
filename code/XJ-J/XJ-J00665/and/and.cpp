#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[200001],i,ma,s;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	s=a[1];
	
	for(i=1;i<=n;i++)
	{
		s=(s&a[i]);
	}
	
	if(m=1)
	{
		for(i=1;i<=n;i++)
		{
			if(a[i]>ma)
			ma=a[i];
		}
		cout<<ma;
		return 0;
	}
	
	cout<<s;
	
	return 0;
}