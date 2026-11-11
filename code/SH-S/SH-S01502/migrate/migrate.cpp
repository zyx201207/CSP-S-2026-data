#include <bits/stdc++.h>
using namespace std;
long long c,t,n[100000],d[100000],x[1000000],ans[100000],pair,num,mina;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for (int i=1;i<=t;i++)
	{
		cin>>n[i]>>d[i];
		for (int j=1;j<=n[i];j++)
		{
			cin>>x[j];
		}
	}
	for (int i=1;i<=t;i++)
	{
	//测试点数 t	
		for (int j=1;j<=n[i];j++)
		{
		//起点数 x[j] 
			long long pair=0;
			for (int q=1;q<=n[i];q++)
			{
				mina=0;
				for (int e=1;e<=n[i];e++)
				{
				//终点数 x[e]	
					if ((x[e]-x[j]<=d[i])&&(x[e]-x[j+1]>d[i]))
					{
						pair++;
						mina+=x[e]-x[j];
					}
					for (int p=1;p<=n[i];p++)
					{	
						int s=x[p]+x[j]+x[e]-x[p];
						if (s==mina)
						{
							pair++; 
						}
					}
				}
			}
			if (pair==2)
			{
				ans[i]++;
			}
		}
	}
	for (int i=1;i<=t;i++)
	{
		cout<<ans[i]<<endl;
	}
	return 0;
}
