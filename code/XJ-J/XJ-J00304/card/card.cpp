#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],b[300005];



int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++){
			b[j]++;
			for(int k=i;k<j;k++)
			{
				if(a[j]==a[k])
				{
					for(int l=k;l<=j;l++)
					{
						a[l]=-1;
						b[l]--;
					}
				}
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<b[i]<<" ";
	return 0;
}
