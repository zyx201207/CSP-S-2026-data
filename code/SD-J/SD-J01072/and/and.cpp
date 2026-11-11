#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fst ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long

const int INF=0x3f3f3f3f3f3f3f3f;
const int N=1e6+10, M=2e6+10;

int n, m;
int a[N], f[N];

signed main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	fst
	cin >> n >> m;
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	for(int i=1; i<=n; i++)
	{
		for(int j=m; j>1; j--)
		{
			f[j]=max(f[j], f[j-1]&a[i]);
		}
		f[1]=max(f[1], a[i]);
	}
	cout << f[m];
	return 0;
}

