#include<bits/stdc++.h>
using namespace std;
long long a[2009][2009],num[2009],b[2009];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,k,m=-1;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>num[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(j!=i)
				a[i][j]=num[i]&num[j];
	int xx,yy;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(m<a[i][j])
			{
				m=a[i][j];
				xx=i,yy=j;
			}
		}
	num[xx]=-1;
	num[yy]=-1;
	for(int i=3;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
			if(num[j]!=-1)b[i]=num[j]&m;
		m=-1;
		for(int j=1;j<=n;j++)
			m=max(m,b[i]);
	}
	cout<<m;
	return 0;
}           
