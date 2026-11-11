#include<bits/stdc++.h>
using namespace std;
int ma[5005][3005],a[5005],ans[3005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		long long cnt=0;
		for(int j=n;j>=i;j--)
		{
		    if(ma[i][a[j]]==1)
			{
				cnt=a[j];
				break;
			}
			ma[i][a[j]]++;
		}
		int p=0,o=0;
		for(int j=n;j>=i;j--)
		{
			if(a[j]==cnt)
			{
				if(o==0)
				{
					p=-1;
					o=1;
				    continue;
				}
				break;
			}
			ma[i][a[j]]+=p;
		}
	}
	for(int j=1;j<=m;j++)
	{
		for(int i=1;i<=n;i++)
		{
			ans[j]+=ma[i][j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
 } 
