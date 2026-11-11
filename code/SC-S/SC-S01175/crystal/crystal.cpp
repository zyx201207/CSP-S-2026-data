#include <bits/stdc++.h>
using namespace std;
const int MAXN = 0x3f3f;
int a[MAXN];
int n,m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int num = 0;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
    for (int i = 1;i <= n;i++)
    {
    	if (a[i] + 1 == a[i + 1])
    	{
    		num++;
		}
	} 
	for (int i = 1;i <= n;i++)
	{
	    for (int k = 1;k <= n;k++)
		{
			if (a[k] + 1 == a[k + 1])
			{
				num++;
			}
		} 
	}
	cout << num / 4;
	return 0;
}