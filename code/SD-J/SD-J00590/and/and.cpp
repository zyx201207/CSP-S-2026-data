#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+1;
int a[N],maxn=-1,maxx=-1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(a[i],maxn);
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i!=j)
				{
					maxx=max(a[i]&a[j],maxx);
				}
			}
		}
		cout<<maxx;
		return 0;
	}
	cout<<maxn;
	return 0;
}
