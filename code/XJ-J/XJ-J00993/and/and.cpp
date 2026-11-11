#include<bits/stdc++.h>
using namespace std;
long long int n,a[200005],m,i,s,maxn=1,j,k=1,v;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	cin>>a[i];
	for(j=1;j<=n;j++)
	{
		for(k=1;k<=n;k++)
		{
		if(j==k)
		k++;
		s=a[j]&a[k];
		if(s>maxn)
		maxn=s;
		}
	}
	v=maxn;
		for(j=2;j<=m;j++)
		{
			for(k=1;k<=n;k++)
			{
				s=v&a[k];
				if(s>maxn)
				maxn=s;
			}
			maxn=s;
			v=maxn;
			k=1;
		}
	cout<<maxn;
	return 0;
}