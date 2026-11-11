#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[100005],b[100005];
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int da=-100000;
	while (m>0)
	{
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				b[i]=(a[i]&a[j]);
			}
		}
		m--;
	}
	for (int i=1;i<=n;i++)
	{
		da=max(da,b[i]);
	}
	cout<<da;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
