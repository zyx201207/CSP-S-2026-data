#include <iostream>
using namespace std;
int n,m,d,f = 0,a[10005];
int main() 
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	d = a[0];
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	for(int i = 0;i < m;i++)
	{
		for(int j = 0;j < n;j++)
		{
			if(a[d] > a[j])
			{
				d = j;
			}
		}
		a[d] += 1;
	}
	for(int i = 0;i < n;i++)
	{
		if(a[d]== a[i])
		{
			f += 1;
		}	
	}
	cout << f; 
	return 0; 
} 
