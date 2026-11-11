#include <bits/stdc++.h>
using namespace std;
int a[5*100000+10],mx;  
int main()
{ 
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int a1[5*100000+10],q=i;
		for(int k=1;k<=n;k++)
		{
			a1[k]=a[k];
		}
		for(int j=i;j<=n;j++)
		{
			for(int k=q;k<=j;k++)
			{
				if(a1[j+1]==a1[k])
				{
					for(int x=q;x<=j;x++)
					{
						a1[x]=-1;
					}
					q=j+1;
					j=q;
				}
			}
		}
		for(int k=i;k<=n;k++)
		{
			if(a1[k]!=-1&&a1[k]!=a[n])
			{
				mx++;
				break;
			}
		}
	}
	if(a[n]==1)
	{
		cout<<n<<" "<<mx;
	}
	else
	{
		cout<<mx<<" "<<n;
	}
	return 0;
}
