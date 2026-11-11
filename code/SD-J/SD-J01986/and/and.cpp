#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[10101010];
int maxx=-1;
int ans;
int main()
{
	freopen("and","r",stdin);
	freopen("and","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+m+1);
	for(int i=m;i>=1;i++)
	{
		int x=a[i];
		for(int j=1;j<=m-n+1;j++)
		{
			x&=a[j];
			maxx=max(x,maxx);
		}
	}
	cout<<maxx;

	return 0;
}
