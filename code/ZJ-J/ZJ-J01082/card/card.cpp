#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N=5e5+5,M=3e5+5;
int a[N];
int b[N];
int c[M];
int cnt[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(c,0,sizeof(c));
		int k=1;
		for(int j=i;j<=n;j++)
		{
			if(c[a[j]]!=0)
			{
				k=c[a[j]];
				b[k]=a[j];
				k++;
				for(int q=1;q<=k-1;q++)
				{
					c[b[q]]=q;
				}
			}
			else
			{
				b[k]=a[j];
				c[a[j]]=k;
				k++;
			}
		}
		for(int j=1;j<=k-1;j++)
		{
			cnt[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
	}
	return 0;
}