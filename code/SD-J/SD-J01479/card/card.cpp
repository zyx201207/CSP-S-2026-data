#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int a[N];
int b[M]={0};
int c[M]={0};
int n,m;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		c[a[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		c[a[i-1]]--;
		int r=i,l=i+1,d[m+5]={0};
		while(l<n)
		{
			if(c[a[r]]-d[a[r]]==1)
			{
				b[a[r]]++;
				r++;
			}
			if(a[r]!=a[l])
			{
				l++;
			}
			if(a[r]==a[l])
			{
				for(int k=r;k<l;k++) d[a[k]]++;
				r=l;
				l++;
			}
		}
		for(int j=r;j<=l;j++)
		{
			b[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<' ';
	}
	return 0;
}
