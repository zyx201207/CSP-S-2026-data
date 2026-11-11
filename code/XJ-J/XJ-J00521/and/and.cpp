#include <bits/stdc++.h>
using namespace std;
int n,m;
int lum[400000];
int ans = 1;
int a[200000];
int numejz[200000];
string ejz[200000];
int changdu[200000];
int beishu;
int pnd[300000];
int bigger[300009];
int smaller[300009];
string zifuend[200009];
int endchangdu[200009];
int main()
{
	ifstream fin ("and.in");
	ofstream fout("and.out");
	fin >> n >> m;
	for (int i = 1;i <= n ;i++ )
	{
		fin >> a[i];
	}
	
	for (int p = 1;p <= n ;p++ )
	{
		while (a[p] <= 1)
		{
			numejz[p] += a[p] % 2;
			ejz[p] = numejz[p] + '0';
			changdu[p] = ejz[p].length();
		}
		
	}
	for (int j = 1; j <= n;j++)
	{
		int sum = 1;
		int bigejz;
		while (ans = m)
		{
			if (changdu[sum] > changdu [ans +1])
			{
				beishu = changdu[sum] - changdu[ans + 1];
				for (int q = 1;q <= beishu;q++)
				{
					numejz[ans + 1] * 10;
				}
			}
			else
			{
				beishu = changdu[ans + 1] - changdu[sum];
				for (int u = 1;u <= beishu;u++)
				{
					numejz[sum] * 10;
				}
			}
			ans++;
		}
		bigger[j] = max(numejz[sum],numejz[sum+1]);
		smaller[j] = min(numejz[sum],numejz[sum+1]);
		pnd[j] = bigger[j] - smaller[j];
		zifuend[j] = numend[j] + '0';
		endchangdu[j] = zifuend[j].length();
		for (int y = 1;y <= endchangdu[j];y++)
		{
			int num = endchangdu[y];
			while (num = 0)
			{
				lum[j] += zifuend[j][1] * 2^(num - 1);
			}
		}
		sum++;
	}
	for (int e = 1;e <= n;e++)
	{
		int zuidaend;
		if (lum[e] > lum[e + 1])
		{
			zuidaend = lum[e];
		}
		else
		{
			zuidaend = lum[e + 1];
		}
		if (zuidaend < lum[n])
		{
			zuidaend = lum[n];
		}
	}
	cout << zuidaend;
	fin.close(); 
	fout.close();
	return 0;
}