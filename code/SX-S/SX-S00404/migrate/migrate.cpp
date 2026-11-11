#include<bits/stdc++.h>
#define int long long
#define for1(l,r,name) for(int name = l;name <= r;name++)
#define for2(r,l,name) for(int name = r;name >= l;name--)
using namespace std;
const int N = 2e6 + 5;
int c,T,n,d,a[N],ans;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> T;
	while(T--)
	{
		ans = 0;
		cin >> n >> d;
		for1(1,n,i) cin >> a[i];
		for1(1,n,i) for1(i + 1,n,j) if((a[j] - a[i]) % d && (a[j] - a[i]) > d) ans++;
		cout << ans << '\n';
	}
	return 0;
}
