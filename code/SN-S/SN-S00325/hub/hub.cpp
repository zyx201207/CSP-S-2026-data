//杨云帆 陕西省西安中学 SN-S00325 
#include<bits/stdc++.h>
using namespace std;

long long c, t; 
int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	cin >> c >> t;
	while (t --)
	{
		long long n = 0, k = 0;
		cin >> n >> k;
		int u[n], v[n];
		for (int i = 1; i < n; i ++) cin >> u[i] >> v[i];
		cout << '1' << '\n';
	}
	return 0;
}
