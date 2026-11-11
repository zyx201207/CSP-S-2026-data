#include <bits/stdc++.h>
using namespace std;
const int MX = 5e5;
int a[MX + 10],ls[MX + 10],output[MX + 10];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,j;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		int lsnum = 0;
		int lsls = 0;
		for(j = i;j <= n;j++)
		{
			ls[lsnum + 1] = a[j];
			lsnum++;
			for(int l = 1;l <= lsnum;l++)
			{
				if(ls[l] == a[j])
				{
					l++;
					for(;l <= lsnum;l++)
					{
						ls[l] = 0;
						lsls++;
					}
					break;
				}
			}
			lsnum -= lsls;
		}
		sort(ls + 1,ls + lsnum + 1);
		for(j = 1;j <= lsnum;j++)
		{
			if(ls[j] != ls[j - 1])
			{
				output[ls[j]]++;
			}
		}
	}
	for(int i = 1;i <= m;i++)
	{
		cout << output[i] << ' ';
	}
	cout << '\n';
	return 0;
} 
