#include<bits/stdc++.h>
using namespace std;
int n,m,num[200005]={0},i,j,k;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>num[i];
	}
	int maxn=-1;
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++)
		{
			for(k=1;k<=n;k++)
			{
				if((num[i] & num[j] & num[k])>=maxn)
				{
					maxn=i & j & k;
				}
			}
		}
	}
	cout<<maxn;
	return 0;
}