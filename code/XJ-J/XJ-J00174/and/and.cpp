#include<bits/stdc++.h>
using namespace std;
int m=3,n;
long long int a[200005],maxn;
int main()
{
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				maxn=max(maxn,a[i]&a[j]&a[k]);
			}
		}
	} 
	cout<<maxn;
	return 0;
}
