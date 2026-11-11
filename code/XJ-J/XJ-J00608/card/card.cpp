#include<bits/stdc++.h>
using namespace std;
int n,i,m,a[1000005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	cin>>a[i];
	for(i=1;i<=m;i++)
	{
		int max=0,k=0,o=0,e=0;
		for(int q=1;q<=n;q++)
		{
			if(a[q]==i)
			{
				max=q;
				
			}
		}
		if(i!=1)
		{
			for(int q=1;q<=max;q++)
			{
				if(a[q]!=i)
				k++;
				if(a[q]==1)
				o++;
				if(a[q]==2)
				e++;
			}
			if(o%2!=0)
			max=max-k;
		}
		cout<<max<<' ';
	}
	return 0;
}