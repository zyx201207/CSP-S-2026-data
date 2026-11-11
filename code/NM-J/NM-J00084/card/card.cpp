#include <iostream>
using namespace std;
int a[100];
int b[100];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i>=n;i++)
	{
		for (int j=i;i<=n;j++)
		{
			if (j==a[i])
			{
				b[i]=j;
			}
		}
	}
	return 0;
}

