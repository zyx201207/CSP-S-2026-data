#include <bits/stdc++.h>
using namespace std;
int c,frq;
int n;
const int N = 2e6 + 7;
int a[N];
int d;
bool flag = 0;
int main()
{
	cin >> c >> frq;
	while(frq--)
	{
		cin >> n >> d;
		for(int t = 1;t <= n;t++)
		{
			cin >> a[t];
		}
		for(int t = 1;t <= n;t++)
		{
			for(int i = t + 1;i <= n;i++)
			{
				dfs(t,i,t);
				if(flag)
				{
					cout << dfs
				}
			}
		}
	}
	return 0;
 } 
