#include<bits/stdc++.h>
using namespace std;
int n,m,a[500050],ans[300050],appear[300050];
bool b[300050];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		memset(b,true,sizeof(b));
		memset(appear,0,sizeof(appear));
		for(int j=i;j<=n;j++)
		{
			if(!appear[a[j]]) appear[a[j]]=j;
			else
			{
				for(int z=appear[a[j]];z<j;z++)
				{
					b[z]=false;
					if(appear[a[z]]) appear[a[z]]=0;
				}
				appear[a[j]]=j;
			}
		}
		for(int j=i;j<=n;j++)
		{
			if(b[j]) ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
