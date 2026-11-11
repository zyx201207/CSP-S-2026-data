#include<bits/stdc++.h>
using namespace std;
const int N = 2000005;
int c , t;
int n , k , u , v;
int main ()
{
//	freopen("migrate.in" , "r" , stdin);
//	freopen("migrate.out" , "w" , stdout);
//	freopen("1.txt" , "r" , stdin);
	freopen("hub.in" , "r" , stdin);
	freopen("hub.out" , "w" , stdout);
	cin >> c >> t;
	for(int i = 1 ; i <= t ; i++)
	{
		cin >> n >> k;
		for(int j = 1 ; j < n ; j++)
			cin >> u >> v;
		if(k >= n / 2)  cout << 1 << "\n";
		else
			cout << ceil((1.0 * (n + 1) / 2 - k) / 4) + 1 << "\n";
	}
}