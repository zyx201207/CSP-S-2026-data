#include<bits/stdc++.h>
using namespace std;
const int N=5e5+3,M=2e5+3;
int n,m,a[N],b[N],t,ans[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
	{
		t=0;
		for(int j=i;j<n;j++)
		{
			b[t]=a[j];
			if(t>0)
			{
				for(int k=0;k<t;k++)
				{
					if(b[k]==b[t])
					{
						int p=t;
						t=k;
						for(int l=k+1;l<=p;l++)
							b[l]=0;
					}
				}
			}
			t++;
		}
		for(int j=0;j<t;j++)
			ans[b[j]]++;
	}
	for(int i=1;i<=m;i++)
		printf("%d ",ans[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

