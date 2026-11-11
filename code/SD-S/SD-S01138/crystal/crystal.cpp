#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e6 + 10;
const int inf = 0x3f3f3f3f3f3f3f3f;
int n,m;
int a[N];
int res = 0;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int l = 1,r = 2;int cnt = 1;int sum = 0;
	while(true)
	{
		if(r > n){break;}
		sum += abs(a[r] - a[r-1]) * (r-1);
		if(sum <= m){res = max(res,r - l + 1);r ++;}
		else if(sum > m){sum -= abs(a[l+1] - a[l]) * l;l ++;}
//		cout << l << " " << r << " " << sum << " " << res << endl;
	}
	cout << res;
	return 0;
}
/*
Oct31==Dec25?
*/

