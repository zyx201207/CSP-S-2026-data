#include<bits/stdc++.h>
using namespace std;
const int MX = 2e5;
int a[MX + 10],b[MX + 10]; 
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,i,j;
	cin >> n >> m;
	for(i = 1;i <= n;i++)
	{
		cin >> a[i]; 
	}
	sort(a + 1,a + n + 1,greater<int>());
	int x = a[1];
	for(i = 2;i <= m;i++)
	{
		x = x & a[i]; 
	}
	int cnt = 0,z = 0;
	for(i = 1;i < n;i++)
	{
		if(a[i] == a[i + 1])
		{
			cnt++;
		}
		else
		{
			cnt = 0;
		}
		if(cnt == m - 1)
		{
			int l;
			l = a[i - cnt + 1];
			for(j = i - cnt + 1 + 1;j <= i + 1;j++)
			{
				l = l & a[j];
			}
			b[++z] = l;
		}
	} 
	sort(b + 1,b + n + 1,greater<int>());
	cout << max(b[1],x) << '\n';
	return 0;
} 
