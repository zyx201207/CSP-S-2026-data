#include <bits/stdc++.h>
using namespace std;
long long n,m,ma=1,a[500010],k;

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
	while(m>0)
	{
		k++;
		if(a[k+1]!=a[k] && m-(a[k+1]-a[k])>=0)
		{
			m=m-(a[k+1]-a[k]);
			a[k]=a[k+1];
			sort(a+1,a+n+1);
			k=0;
		}
	}
	for(int i=1;i<n;i++)
	{
		if(a[i]==a[i+1])
		{
			ma++;
		}
	}
	cout<<ma;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
