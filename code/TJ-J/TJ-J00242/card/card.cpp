#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500001],f = 1,b[500001],c[500001];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	int cnt = n;
	while(cnt--)
	{
		for(int i = 1;i <= m;i++)
		{
			c[i] = 0;
		}
		//cout << endl;
		for(int i = f;i <= n;i++)
		{	
		    //cout << i << " ";
			if(c[a[i]] == 1)
			{
				int p = a[i];
				for(int j = 1;j < i;i++)
				{
					if(a[j] == p)
					{
						p = j;
						break;
					}
				}
				for(int j = i;j >= p;j--)
				{
					c[j] = 0;
				}
			}
			c[a[i]]=1;
//			for(int j = 1;j <= m;j++)
//			{
//				cout << c[j];
//			}
//			cout << endl;
			if(i == n)
			{
				for(int k = 1;k <= n;k++)
				{
					if(c[k] == 1)
					{
						//cout << k << " ";
						//cout << c[k] << " ";
						b[k]++;
					}
				}
			}
		}
		f++;
		if(cnt == 0)
		{
			for(int i = 1;i <= m;i++)
			{
				//cout << endl;
				cout << b[i] << " ";
			}
		}
	}
	return 0;
 } 
