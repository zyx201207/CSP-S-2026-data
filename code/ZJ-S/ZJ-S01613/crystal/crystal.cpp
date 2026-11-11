#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,z=0;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		b[i]=b[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int s=0;
		for(int p=i;p>0;p--)
		{
			if(a[i]*(i-p+1)-b[i]+b[p-1]>m)
			{
				break;
			}
			s++;
		}
		z=max(z,s);
	}
	cout<<z;
	fclose(stdin);
	fclose(stdout);
	return 0;
}