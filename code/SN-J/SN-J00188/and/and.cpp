#include<bits/stdc++.h>
using namespace std;

int a[200005];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	int maxn = 0;
	int k = 0;
	for(int i = 1;i <= n;i++) 
	{
		for(int j = i + 1;j <= n;j++)
		{
			for(int x = i;x <= m;x++)
			{
				k = a[i] & a[i + x];
			}
			maxn = max(k,maxn);
		}
		
	}
	cout << maxn;
}
