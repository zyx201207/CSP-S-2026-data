#include<bits/stdc++.h> 
using namespace std;
long long a[1000000001];

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	long long n, m;
	cin >> n >> m;
	for(int i = 0; i <= n; i++)
	{
		cin >> a[i];
		a[i] != a[i + 1];
		sort(a[i], a[i+1]);
	}
	long long i ;
	
	
	
	for(int y = 0; y <= m; y++)
	{
	cout << i;
    }
	return 0;
}
