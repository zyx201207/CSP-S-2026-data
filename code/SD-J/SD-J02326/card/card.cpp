#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int a[500005],m1[300005],m2[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{	m1[a[i]]++;
		if(m1[a[i]]!=0)
		{
			for(int j=1;j<=i;j++)
			{
				m1[a[j]]--;
			}
		}
		for(int t=1;t<=n;t++)
		{
			m2[i]=m1[i];
			m1[i]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<m2[i];
	}
	return 0;
}
