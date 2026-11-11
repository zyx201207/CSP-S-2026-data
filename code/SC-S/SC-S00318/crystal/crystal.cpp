#include <bits/stdc++.h>
using namespace std;
int n,m,a[100005],tnt,zzjg;
int com(int x[100005],int y,int z)
{
	int zd = x[y];
	for (int i = y;i <= z;i++)
	{
		zd = max(zd,x[i]);
	}
	return zd;
} 
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	bool zdm = false;
	for (int j = 1;j < n;j++) 
	{
		if(a[0] != a[0 + j]) zdm = true;
	}
	if(zdm == false)
	{
		cout << 0 << endl;
		return 0;
	}
	for (int i = 1;i < n;i++)
	{
		for (int j = 0;j < n;j++) 
		{
			zzjg = i + 1;
			for (int k = j;k <= j + i;k++)
			{
				tnt = 0;
				int maxm = com(a,k,k + i);
				for (int wb = k;wb <= k + i;wb++)
				{
					tnt += maxm - a[wb];
				}
				int js = 0;
				for (int wx = 1;wx < n;wx++) 
	            {
		            if(a[wx] == maxm) js += 1;
	            }
	            if(js > 1) zzjg += 1;
				if(tnt == m)
			    {
					cout << zzjg << endl;
	                return 0;
			    }
			}
			
		}
	}
	cout << 0 << endl;
	return 0;
}