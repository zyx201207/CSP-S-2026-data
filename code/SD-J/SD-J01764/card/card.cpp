#include<bits/stdc++.h>

using namespace std;

long long m , n;
long long  a[100010];
long long b[100010]={0};
long long c[100010]={0};
long long d[100010]={0};
long long e[100010]={0};
int main ()
{
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		d[i]+=a[i];
	}
	sort(d+1 , d+n+1);
	int y=d[n];
	for (int i = 1;i <= n;i++)
	{
		int l=0;
		for(int j = i;j <= n;j++)
		{
			l++;
			b[l]+=a[j];
			c[a[j]]++;
			//for (int h = 1;h <= l;h++)
			//{
		//		cout << b[h] << " ";			
		//	}
			//cout << endl;
			if(c[a[j]] > 1)
			{
				int hj=b[l];
				for(int h = 1;h <= n;h++)
				{
					b[h]=0;
				}
				b[1]+=hj;
				l=1;
				for(int h=1;h <=y;h++)
				{
					c[h]=0;
				}
				c[b[1]]++;
			}
			else
			{
				continue;
			}
		}
		//cout << endl;
		//cout << endl;
		for (int h = 1;h <= l;h++)
		{
			e[b[h]]++;
		}
		for (int h=1;h<=n;h++)
		{
			b[h]=0;
			c[h]=0;
		}
	}
	for (int i = 1;i <= m;i++)
	{
		cout << e[i] << " ";
	}
	return 0;
}

