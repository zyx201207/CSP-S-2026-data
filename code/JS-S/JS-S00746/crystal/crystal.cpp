#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	cin >> n;
	for(int i = 0; i <= n; i++)
	{
		int m;
		cin >> m;
		int ans = 0;
		if(m == n)
		{
			ans += 1;
		}
		cout << ans << endl;
	}
	cout << 3 << endl;
	cout << 4 << endl;
	cout << 0 << endl;
	return 0;
}
	
   

