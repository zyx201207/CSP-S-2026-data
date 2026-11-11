#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,s[10000][10000]={0},maxx=1;
int main()
{
	freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int a,b;
    cin>>a>>b;
    int ans[b+1];
    int sum[b+1];
    for(int l=1;l<=b;l++)
    {
    	int n,d;
    	cin>>n>>d;
    	int a[n+1][4];
    	for(int i=1;i<=n;i++)
		{
			cin>>a[i][0];
			if(i!=1)
			{
				a[i][1]=a[i][0]-a[i-1][0];
			}
			if(i>=4)
			{
				a[i-1][2]=a[i-1][1]+a[i-2][1];
			}
		} 
		for(int i=3;i<=n;i++)
		{
			if(a[i][2]<d)
			{
				a[i][3]=1;
			}
			else
			{
				a[i][3]=0;
			}
		}
		int sum=0;
		for(int i=3;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				sum+=a[j];
			}
			if(sum%2==0)
			{
				ans[l]++
			}
		}
	}
	for(int i=1;i<=b;i++)
	{
		cout<<ans[i]<<endl;
	}
	
	return 0;
}
