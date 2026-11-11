#include <iostream>
#include <stack>
using namespace std;
stack <int> s;
stack <int> ss;
int a[300009];
int ans[300009],b[300009],c[300009];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	return 0;
	int n,m,w;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(a[b[j]]==1 or a[b[j]]==2)
			{
				c[b[j]]=j;
				a[b[j]]=2;
			}
			else
			{
				a[b[j]]=1;
			}
		}
		for(int j=i;j<=n;j++)
		{
			
			if(a[b[j]]==2)
			{
				j=c[b[j]];
				ans[b[j]]++;
			}
			else
			{
				ans[b[j]]++;
			}
		}
		for(int j=1;j<=m;j++)
		{
			a[j]=0;
			c[j]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}




