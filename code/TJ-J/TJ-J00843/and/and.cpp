#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
long long a[maxn];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
    	cin >> a[i];
	}
	sort(a,a+n);
	int cnt = a[n];
	for(int i = n - 1; i >= n - m; i--)
	{
		cnt = cnt & a[i];
	}
	cout << cnt;
    return 0;
}
