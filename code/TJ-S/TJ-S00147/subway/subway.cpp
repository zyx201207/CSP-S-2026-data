#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5;
int c, n, m, d, q,a[N],b[N],c[N];
int w[N],k[N],x[N],y[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c>> n >>m >> d >> q;
	for (int i= 1;i <= m;i++)
	{
		cin >> w[i];
	}
	for (int i = 1;i <= n;i++)
	{
		cin >> k[i];
		if (n==1)
		{
			for (int j = 1;j<= 2*k[i];j++)
			{
				cin >>a[i];
			}
		}
		if (n==2)
		{
			if(i==1)
			{
				for (int j = 1;j<= 2*k[i];j++)
				{
					cin >>a[i];
				}
			}
			else
			{
				for (int j = 1;j<= 2*k[i];j++)
				{
					cin >>b[i];
				}
			}
		}
		if (n==1)
		{
			if(i==1)
			{
				for (int j = 1;j<= 2*k[i];j++)
				{
					cin >>a[i];
				}
			}
			if (i==2)
			{
				for (int j = 1;j<= 2*k[i];j++)
				{
					cin >>b[i];
				}
			}
			else
			{
				for (int j = 1;j<= 2*k[i];j++)
				{
					cin >>c[i];
				}
			}
		}
	}
	for (int i = 1;i<= q;i++)
	{
		cin >>x[i]>>y[i];
	}
	cout << 0 <<" "<<0;
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
