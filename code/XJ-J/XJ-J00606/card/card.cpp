#include<bits/stdc++.h>
using namespace std;
long long int i,j,n,m,a[10000005],sum,k;
long long int q[100005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	cin>>a[i];
	k=1;
	while(k<=n)
	{
		if(k>m)
		{
		cout<<sum;
		return 0;	
		}
		else
		{
			for(j=k;j<=n;j++)
			{
				
				sum++;
				for(i=1;i<=n;i++)
				{
				if(j==a[i])
				sum++;
			    if(q[i]==a[j])
			    {
			    
				}
				
			    }
			}
		}
	}
	return 0;
}
