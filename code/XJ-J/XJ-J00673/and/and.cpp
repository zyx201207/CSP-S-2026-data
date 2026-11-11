#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[20005],b[20005],i,j,k,s,maxn=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		for(j=1;j<i;j++)
		{
			b[j]=a[i]&a[i-j];
			k++;
		}
	}
	for(i=1;i<=k;i++)
	{
		s=0;
		for(j=i;j<=k;j++)
		{
			if(b[i]==b[j]&&b[i]!=0)
			s++;
		}
		if(s==m)
		{
			if(b[i]>maxn)
			maxn=b[i];
		}
	}
	cout<<maxn;
}