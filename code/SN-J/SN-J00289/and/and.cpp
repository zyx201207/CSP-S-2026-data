#include <bits/stdc++.h>
using namespace std;
long long number[20005];
int n,m;
int find;

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin.tie(0);
    
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++)
	{
		cin >> number[i];
	}    
	sort(number + 1, number + n + 1);
	
	long long x = number[n];
	
	for (int i = 1; i < m; i++)
	{
		x &= number[n - 1];
	}
	
	cout << x;
    
    return 0;
}
