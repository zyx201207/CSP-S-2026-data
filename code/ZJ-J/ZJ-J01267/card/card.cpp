#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],ans[300001],ea[300001],p[300001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%d",&a[n-i+1]);
	for(int i=1;i<=n;i++) ans[a[n-i+1]]+=i;
	for(int i=1;i<=n;i++)
	{
		if(ea[a[i]]!=0) 
		{
			for(int j=ea[a[i]];j<i;j++)
				if(a[j]!=-1)
				{
					ans[a[j]]-=(n-i+1);
					ea[a[j]]=p[a[j]];
					a[j]=-1;
				}
		}
		p[a[i]]=ea[a[i]];
		ea[a[i]]=i;
	}
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	return 0;
}