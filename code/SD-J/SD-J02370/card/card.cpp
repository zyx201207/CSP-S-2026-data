#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],b[500005],c[300005],d[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(c[a[i]]!=0)
		{
			b[c[a[i]]]=i;
			c[a[i]]=i;
		}else{
			c[a[i]]=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int j=i;
		while(j<=n)
		{
			if(b[j]!=0)
			{
				j=b[j];
			}else{
				d[a[j]]++;
				j++;
			}
			
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<d[i]<<" ";
	}
	return 0;
}//100+100+35~60+35~60=310
//270~320
