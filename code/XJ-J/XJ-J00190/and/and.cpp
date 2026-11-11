#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,maxn;
int a[N],sum;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum++;
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			maxn=max(maxn,a[i]);
		}
	}
	else if(m==n)
	{
		maxn=a[1];
		for(int i=1;i<=n;i++)
		{
			maxn=maxn&a[i];
		}
	}
	else
	{
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				maxn=max(maxn,a[i]&a[j]);
			}
		}
	}
	cout<<maxn;
}
