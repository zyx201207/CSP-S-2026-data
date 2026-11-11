#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
#define FOR(w, a) for(int i = w; i <= a; i++)
#define I ios::sync_with_stdio(0);
#define AC cin.tie(0);
#define T4 cout.tie(0);
#define l first
#define r second
#define pb push_back
const int N = 5e5 + 10;
const int M = 3e5 + 10;
int a[N], t[M], cf[N], ans[M], tt[M];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	I AC T4
	int n, m;
	cin >> n;
	cin >> m;
	FOR(1, n) cin >> a[i];
	for(int k = 1; k <= n; k++)
	{
		FOR(k, n)
		{
			if(t[a[i]])
			{
				cf[t[a[i]]]++, cf[i]--;
				int j = t[a[i]];
				while(j < i)
				{
					t[a[j]] = 0;
					j++;
				}
			}
			t[a[i]] = i;
		}
		FOR(k, n) cf[i] += cf[i - 1];
		FOR(k, n) if(cf[i] == 0) tt[a[i]] = 1;
		FOR(1, m) if(tt[i] != 0) ans[i]++;
		FOR(1, n) cf[i] = 0, tt[i] = 0, t[i] = 0;
	}
	FOR(1, m) if(ans[i] != 0) cout << ans[i] << " "; 
	return 0;
}
