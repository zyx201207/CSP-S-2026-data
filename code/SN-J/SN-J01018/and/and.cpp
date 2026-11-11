#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int main()
{
	//freopen("and.in", "r", stdin);
	//freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[N];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort (a + 1, a + n + 1);
	int maxx = a[0];
	if(m == n){
		maxx = a[0];
		for(int i = 1; i < n; i++)
			maxx = maxx & a[i];
		cout << maxx;
		return 0;
    }
	for(int i = 0; i < n; i--)
	{
		for(int j = 1; j <= m; j++)
			maxx  = maxx & a[i - j];
	}
	cout << maxx;
	return 0;
}
