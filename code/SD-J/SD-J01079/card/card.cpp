#include <iostream>
using namespace std;
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	bool sk[100000];
	cin >> n >> m;
	int a[700000], b[40000];
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = i; j <= n; j++)
		{
			if(sk[a[j]] == 0)
			{
				sk[a[j]] = 1;
			}else if(sk[a[j]] == 1)
			{
				for(int k = 1; k <= n; k++)
				{
					sk[k]= 0;
				}
				sk[a[j]] = 1;
			}
		}
		for(int j = 1; j <= n; j++)
		{
			if(sk[j] == 1)
			{
				b[j]++;
			}
		}
	}
	for(int i = 1; i <= n; i++)
	{
		cout << b[i] << " ";
	}
	return 0;
}

