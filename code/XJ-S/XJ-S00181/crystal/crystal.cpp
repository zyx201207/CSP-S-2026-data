#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,maxn=-1,x;
int a[500005],f[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	 cin>>a[i];
	sort(a+1,a+1+n);
	
	for(i=0;i<n;i++)
	{
		j=1;
		x=m;
		while(x>=0)
		{
			while(a[i+j]==a[i+j+1])
			 j++;
			x-=j; a[i+j]++;
		}
		while(a[i+j]==a[i+j+1])
		 j++;
		maxn=max(maxn,j);
	}
	cout<<maxn;
	return 0;
}
