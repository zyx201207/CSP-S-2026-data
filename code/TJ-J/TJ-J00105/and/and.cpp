#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,a[N];
//int C()
//{
//	int num=1;
//	for (int i = 2; i <= n;i++)
//	{
//		num*=i;
//	}
//	int numm=1;
//	for (int i = 2; i <= m;i++)
//	{
//		numm*=i;
//	}
//	int nnumm=1;
//	for (int i = 2; i <= n-m;i++)
//	{
//		nnumm*=i;
//	}
//	int Result=num/numm/nnumm;
//	return Result;
//}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >>n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
//	int num= C();
	if (m==n)
	{
		int sum=a[1];
		for (int i = 2; i <= n;i++)
		{
			sum&=a[i];
		}
		cout << sum;
		return 0;
	}
	int minn=123456789;
	if (m==1)
	{
		for (int i = 1; i <= n;i++)
		{
			if (a[i]< minn)
			{
				minn=a[i];
			}
		}
		cout << minn;
		return 0;
		
	}
	int ar; 
	if (m==2)
	{ 
		int maxn=-1;
		for (int i = 1; i <= n;i++)
		{
			for (int j = i+1; j <= n;j++)
			{
				ar =  a[i] & a[j];
				if (ar > maxn)
				{
					maxn=ar;
				}
			}
		}
		cout << maxn;
		return 0;
	} 
	if (m==3)
	{ 
		int maxn=-1;
		for (int i = 1; i <= n;i++)
		{
			for (int j = i+1; j <= n;j++)
			{
				for (int k = j+1; k <= n;k++)
				{
					ar =  a[i] & a[j] & a[k];
					if (ar > maxn)
					{
						maxn=ar;
					}
				}
			}
		}
		cout << maxn;
		return 0;
	} 
	if (m==4)
	{ 
		int maxn=-1;
		for (int i = 1; i <= n;i++)
		{
			for (int j = i+1; j <= n;j++)
			{
				for (int k = j+1; k <= n;k++)
				{
					for (int l = k+1; l <= n;l++)
					{
						ar =  a[i] & a[j] & a[k];
						if (ar > maxn)
						{
							maxn=ar;
						}
					}
				}
			}
		}
		cout << maxn;
		return 0;
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
