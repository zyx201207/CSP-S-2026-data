#include <bits/stdc++.h>
using namespace std;
int n,m,ant,k,ca[1000010],cnt;
int a[10086];
int fr(int q)
{
	for (int i=1;i<=ant;i++)
	{
		if (ca[i]==q)
		{
			return i;
		}
		else
		{
			return false;
		}
	}
}

int main()
{
	freopen ("card.in","r",stdin);
	freopen ("card.out","w",stdout);
	
	for (int i=1;i<=m;i++)
	{
		cin>>a[i];
		for (int j=i;j<=n;j++)
		{
		int flat=fr(a[i]);
		{
			if (flag=='0')
			{
				ca[i]=a[i];
				ant++;
			}
			else
			{
				for (int p=flag,p<=i;p++)
				{
					ca[p]=0;
				}
			}
		}
		if (ca[ca.length()]==i)
		cnt++;
	}
	cout<<cnt<<" ";
	}
	
	
	
	
	
	return 0;
}
