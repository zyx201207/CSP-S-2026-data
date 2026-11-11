#include <bits/stdc++.h>
using namespace std;
int a[2005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int f;
	for(int i=1;i<m;i++)
	{
		int x,y;
		int maxn=-1;
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(a[j]>=0&&a[k]>=0&&j!=k)
				{
					if((a[j]&a[k])>maxn)
					{
						x=j;
						y=k;
						maxn=(a[j]&a[k]);
					}
				}
			}
		}
		a[x]=-1;
		a[y]=maxn;
		f=maxn;
	}
	cout<<f;
	fclose(stdin);
	fclose(stdout);
	return 0;
}