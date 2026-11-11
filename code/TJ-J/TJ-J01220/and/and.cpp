#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long maxx[200005];
int main()
{
	/*freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);*/
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	int max1=-1e9;
	int flag=1;
	int max3=-1e9;
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]>max3)
			{
				max3=a[i];
			}
		}
		cout<<max3;
		return 0;
	}
    for(int i=1;i<=n;i++)
    {
    	int p=i;
		for(int j=1;j<=m-1;j++)
    	{
    		for(int x=1;x<=n;x++)
    		{
    				if(a[i]!=a[x])
    				{
    					if((a[i]&a[x])>max1)
    					{
    						max1=a[i]&a[x];
    						i=max1;
						}
					}
			}
		}
		i=p;
		maxx[i]=max1;
		max1=-1e9;
	}
	int max2=-1e9;
	for(int i=1;i<=n;i++)
	{
		if(maxx[i]>max2)
		{
			max2=maxx[i];
		}
	}
	cout<<max2;
    return 0;
}
