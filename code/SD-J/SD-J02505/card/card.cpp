#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 5;
const int M = 3 * 1e5 + 5;
int q[N],sz = 0,head = 0;
void push(int x)
{
	sz++;
	q[head + sz] = x;
}
void pop()
{
	sz--;
	head++;
}

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	int n,m;
	cin >> n >> m;
	int a[N];
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	int b[M] = {};
	for (int i = 1;i <= n;i++) 
	{
		for (int i = 0;i < sz;i++)
			q[i] = 0;
		sz = 0;
		head = 0;
		for (int j = i;j <= n;j++)
		{
			push(a[j]);
			int y;
			for (int k = 0;k < sz;k++)
			{
				if (q[k] == a[j])
				{
					y = k;
					break;
				}
			}
			while (y--)
				pop();
		}
		for (int j = 0;j < sz;j++)
		{
			b[q[j]]++;
		}
	}
	for (int i = 1;i <= m;i++)
		cout << b[i] << " ";
	return 0;
} 
//11：19：：我请问呢DEVC++你就继续阴我吧，我一点也不苦一点也不累 
