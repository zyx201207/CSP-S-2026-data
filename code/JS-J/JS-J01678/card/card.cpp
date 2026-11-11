#include<bits/stdc++.h>
using namespace std;
const int p = 500005;
const int q = 300005;

int n, m, a[p], x[p], ans[q], tp[p];
bool f[q];
vector<int> v[q];

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
		cin >> a[i];
		x[i] = v[a[i]].size();
		v[a[i]].push_back(i);
    }
    for(int i=1; i<=n; i++)
    {
		memset(f, 0, sizeof(f));
		for(int j=i; j<=n; j++)
		{
			if(x[j]+1 < v[a[j]].size()) j=v[a[j]][x[j]+1]-1;
			else if(!f[a[j]])
			{
				ans[a[j]]++;
				f[a[j]] = 1;
			}
		}
    }
    for(int i=1; i<=m; i++)
		cout << ans[i] << ' ';
    return 0;
}
