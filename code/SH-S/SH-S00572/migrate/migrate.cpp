#include<bits/stdc++.h>
using namespace std;
int a[10010][10010][2];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n;
	long long d;
	long long x[10010]={};
	cin >> c >> t;
	for(int j = 1;j <= t;j++)
	{
		cin >> n >> d;
		for(int i = 0;i<=n+10;i++)
		{
			for(int k=i;k<=n+10;k++)
			{
				a[i][k][0] = 0;
				a[i][k][1] = 0;
			}
		}
		for(int i = 1;i <= n;i++)
		{
			cin >> x[i];
		}
		for(int i = 1;i<n;i++)
		{
			int b = 1;
			while(i+b<=n&&x[i+b]-x[i]<=d)
			{
				a[i][i+b][0]=1;
				a[i][i+b][1]=1;
				b++;
			}
		}
		for(int i = 2;i<=n;i++)
		{
			for(int k = i-1;k>=1;k--)
			{
				if(a[k][i][0]==0)
				{
					break;
				}
				for(int l = 1;l<k;l++)
				{
					if(a[l][i][0]==0)
					{
						a[l][i][0] = a[l][k][0]+1;
						a[l][i][1]=1;
					}
					else
					{
						if(a[l][i][0]>a[l][k][0]+1)
						{
							a[l][i][0] = a[l][k][0]+1;
							a[l][i][1] = a[l][i][1];
						}
						else if(a[l][i][0]==a[l][k][0]+1)
						{
							a[l][i][1] += a[l][k][1];
						}
					}
				}
			}
		}
		int cnt =0;
		for(int i = 1;i<n;i++)
		{
			for(int k = i+1;k <= n;k++)
			{
				if(a[i][k][1]==2)
				{
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
		
	}
	return 0;
}
