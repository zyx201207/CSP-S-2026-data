#include<bits/stdc++.h>
using namespace std;
int x[500001],y[300001],z[300001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a,b;
	cin>>a>>b;
	for (int i=1;i<=a;i++)
		cin>>x[i];
	for (int i=a;i>=1;i--)
		if (y[x[i]]==0)
			y[x[i]]=i;
	for (int i=1;i<=a;i++)
	{
		int j=i;
		while (j<=a)
		{	
			z[x[j]]++;
			j = y[x[j]]+1;
		}
	}
	for (int i=1;i<=b;i++)
		cout<<z[i]<<" ";
	return 0;
}
