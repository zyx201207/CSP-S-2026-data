//card
#include<bits/stdc++.h>
using namespace std;
const int MAX = 5e5+5;
int a[MAX],ans[MAX],x[MAX];
bool v[MAX];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m; scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	for(int i=1; i<=n; i++)
	{
		memset(v,0,sizeof(v));
		for(int j=i; j<=n; j++)
		{
			bool f = 1;
			for(int s=j-1; s>=i; s--)
			{
				if(v[s]) continue;
				if(a[s] == a[j])
				{
					f = 0;
					break;
				}
			}
			if(f) ans[a[j]]++;
			if(!f)for(int s=j-1; s>=i; s--)
			{
				if(v[s]) continue;
				if(a[s] == a[j]) break;
				ans[a[s]]--;
				v[i] = 1;
			}
		}
	}
	for(int i=1; i<=m; i++)
		printf("%d ",ans[i]);
	printf("\n");
	return 0;
}
