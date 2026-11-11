#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[1000005],i,j,sum=INT_MAX,maxn=-1,f,ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=0;i<n;i++)
	 cin>>a[i];
	 
	for(i=0;i<(1<<n);i++)
	{
		f=0;
		sum=INT_MAX;
		for(j=0;j<n;j++)
		{
			if(i&(1<<j))
			{
				f++;
				sum=(sum&a[j]);
			}
		}
		if(f==m&&maxn<sum)
		 maxn=sum;
	}
	cout<<maxn;
	return 0;
}
