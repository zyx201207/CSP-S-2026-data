#include <bits/stdc++.h>
using namespace std;
int n,m,a[50005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int num=0;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		int l=i;
		for(int j=i;j<=n;j++)
		{
			
			a[j]=a[i];
			if(a[j]==a[j-1])
			{
				a[j]=0;
			}
			if(a[j]==l)
			{
				num++;
			}
		}
	}
	if(num!=0)
	{
		cout<<num;
	}
}
