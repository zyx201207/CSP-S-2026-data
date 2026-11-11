#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
int a[maxn];
int table[maxn];
void findd(need)
{
	for(int i =  1; i <=(intzeof 
}
int main()
{
	freopen("card.in"r", stdin);
	freopen("card.out", "w, 
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int tail = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = i; j <= n; j++)
		{
			bool flag = 0;
			int j = 1;
			for(; j <= n; j++)
			{
				if(table[j] == a[i])
				{
					flag = 1;
					break;
					
				}
			}
			if(flag)
			{
				table[++tail] = a[j];
			}
			else
			{
				tail = j;
				table[tail + 1] = a[j];
				
			}
		}
		for(int j = 1; j <= m; j++)
		{
			findd();
		}
			
	}
		
	return 0;
}
