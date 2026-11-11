#include<bits/stdc++.h>
using namespace std;
int st[1005];
int f(int n, int m)
{
	return n & m;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, maxn=-2e9;
	cin >> n >> m;
	for(int i=1; i<=n; i++)cin >> st[i];
	for(int i=1; i<=n; i++)
	{
		int k=1, a=st[i];
		for(int j=0; j<=n; j++)
		{
			if(j+m-1<=n)
			{
				while((--m)--)
				{
					a=f(a,st[k])
					k++;
				}
				if(a>maxn)
				{
					maxn=a;
				}
			}
			else
			{
				k=1;
				while((--m)--)
				{
					a=f(a,st[k])
					k++;
				}
				if(a>maxn)
				{
					maxn=a;
				}
			}
		}
	}
	cout << maxn;
}
