#include<bits/stdc++.h>
using namespace std;
long long a[1000005],a1[1000005],n,m;
int maxn=-1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1+i;j<=n;j++)
		{
			a1[i]=(a[i]&a[j]);
//			cout<<a1[i]<<" ";
		}
	} 
	for(int i=1;i<=n;i++)
	{
		if(a1[i]>maxn)
		{
			maxn=a1[i];
		}
	}
	cout<<maxn;
	return 0;
}
