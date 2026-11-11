#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int p[500005],top=0;
long long ans[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		top=0;
		for(int j=i;j<=n;j++)
		{
			p[++top]=a[j];
			for(int k=top-1;k>0;k--)
				if(p[k]==p[top])
				{
					top=k;
					break;
				}
		}
		for(int j=1;j<=top;j++)ans[p[j]]++;
	}
	for(int i=1;i<=m;i++)printf("%d ",ans[i]);
	return 0;
}
