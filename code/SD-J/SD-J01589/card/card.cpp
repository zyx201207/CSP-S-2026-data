#include <bits/stdc++.h>
using namespace std;
int a[50050],boo[30050][2],sum[30050],n,m;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(boo[a[j]][0]==1)
			{
				for(int p=boo[a[j]][1]+1;p<j;p++)
				{
					boo[a[p]][0]=0;
				}
			}
			else
			{
				boo[a[j]][0]=1;
				boo[a[j]][1]=j;
			}
		}
		for(int j=1;j<=m;j++){
			if(boo[j][0]==1){
				sum[j]++;
				boo[j][0]=0;
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<sum[i]<<" ";
}
