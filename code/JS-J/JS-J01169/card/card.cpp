#include<bits/stdc++.h>
using namespace std;
int a[500005];
int aa[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n;
	int m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		aa[a[i]]++;
		for(int j=i+1;j<=n;j++)
		{
			if(a[j]>a[j-1])
			{
				aa[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<aa[i]<<" ";
	}
	return 0;
}
