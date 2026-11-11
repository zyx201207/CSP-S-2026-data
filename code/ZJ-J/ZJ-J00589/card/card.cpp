#include<bits/stdc++.h>
using namespace std;
int n,m,d[300005][300005];
vector <int> a(500005);

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
    cin>>n>>m;
    for (int i=1;i<=m;i++) d[0][i]=0;
    for (int i=0;i<n;i++)
    {
    	cin>>a[i];
    	d[i][a[i]]=d[i-1][a[i]]+1;
    	for (int j=1;j<=m;j++)
    	{
    		if (j!=a[i]) d[i][j]=d[i-1][j];
		}
		if (d[i][a[i]]==2)
		{
			int k=i;
			while (d[k][a[i]]==1)
			{
				for (int j=1;j<=m;j++)
				{
					d[k][j]--;
				}
				k--;
			}
		}
	}
    for (int i=1;i<=m;i++)
    {
    	cout<<dp[n][i]<<" ";
	}
	
	return 0;
}
