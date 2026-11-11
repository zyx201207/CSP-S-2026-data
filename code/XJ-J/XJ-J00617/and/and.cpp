#include<bits/stdc++.h>
using namespace std;
long long int maxn=-1,n,m,a[200005],i,s,j,k;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	cin>>a[i];
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			s=a[i];
			for(k=j;k<=n;k++)
			{
				s=(s&a[k]);
			}
			if(s>maxn)
			maxn=s;
		}
	}
	cout<<maxn;
	return 0;
}