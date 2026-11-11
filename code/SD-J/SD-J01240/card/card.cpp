#include<bits/stdc++.h>
using namespace std;
int ans[300900],a[500800],t[300900],tt[300900];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(t[a[j]]!=0)
			{
				for(int x=t[a[j]];x<=j-1;x++)
				{
					tt[x]=1;
					t[a[x]]=0;
				}
			} 
			t[a[j]]=j;
		}
		for(int j=i;j<=n;j++)
		{
			if(tt[j]==0) ans[a[j]]++;
			tt[j]=0;
			t[j]=0;
		}
	}
	for(int j=1;j<=m;j++)
		cout<<ans[j]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
