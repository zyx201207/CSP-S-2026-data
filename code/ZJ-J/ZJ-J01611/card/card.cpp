#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,a[N],c[N],se[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int k=1;
		for(int j=i;j<=n;j++)
		{
			for(int p=1;p<=k;p++)
			{
				if(se[p]==a[j])
				{
					for(int l=p;l<=k;l++)se[l]=0;
					k=min(k,p);
				}
			}
			se[k]=a[j];
			k++;
		}
		for(int j=1;j<=k-1;j++)c[se[j]]++;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
} 
