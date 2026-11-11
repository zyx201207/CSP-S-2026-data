#include<bits/stdc++.h>
using namespace std;
int x[5010],lg[5010][5010],sum[5010];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		cin>>x[1];
		lg[1][1]=0;
		for(int i=2;i<=n;i++)
		{
			lg[i][i]=0;
			cin>>x[i];
			if(x[i]-x[i-1]<=d)
			{
				lg[i][i-1]=x[i]-x[i-1];
				lg[i-1][i]=x[i]-x[i-1];
			}
		}
		for(int l=1;l<=n;l++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(l!=i&&l!=j)
					{
						if(lg[i][j]==lg[i][l]+lg[i][l])
							sum[j]++;
						lg[i][j]=min(lg[i][j],lg[i][l]+lg[i][l]);
					}
				}
			}
		}
		int num=0;
		for(int i=1;i<=n;i++)
		{
			if(sum[i]==2)
				num++;
		}
		cout<<num;
	}
    return 0;
}
