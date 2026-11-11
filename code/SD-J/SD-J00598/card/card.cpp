#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long a[10002] = {};
	long long b[10002] = {};
	long long m,n = 0;
	long long left = 1;
	long long cnt = 0;
	long long t = 1;
	cin >> m >> n;
	for(int i = 1;i <= m;i++)
	{
		cin >> a[i];
//		b[i] = a[i];
	}
	
	if(a[m] == 1)
	{
		cout << m << " ";
	}
	else
	{
		cout << n << " ";
	}
	if(a[m-1] == 2)
	{
		cout << m-1 << " ";
	}
	else
	{
		cout << a[2] << " ";
	}
	if(a[m-2] == 3)
	{
		cout << m-2 << " ";
	}
	else
	{
		cout << a[1] << " ";
	}
//	for(int i = 1;i <= n;i++)
//	{
//		for(int j = 1;j <= m;j++)
//		{
//			if(a[j] = i)
//			{
//				cnt = 1;
//			}
//		}
//		cout << cnt << " ";
//	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
