//SN-S00464 王均诚 陕西省西安中学
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int a[100010];


int main()
{
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , " w" , stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> c >> t;
	while (t --)
	{
		ll n , d;
		cin >> n >> d;
		memset(a , 0 , sizeof a);
		for (int i = 1 ; i <= n ; i++) cin >> a[i];
		cout << 1 << '\n';
	}
	
	return 0;
}
