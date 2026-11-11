#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
set<ll> s;
ll n, m, a[500005], ans[300005];
auto k = s.begin();
int main()
{
	freopen("card1.in","r",stdin);
	freopen("cand.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	for(int i = 1;i <= n;i++)
	{
		s.clear();
		for(int j = i; j <= n;j++)
		{
			if(s.find(a[j]) != s.end())
			{
				k = s.find(a[j]);
				while(k != s.end())
					s.erase(k);
				
			}
			s.insert(a[j]);
		}
		for(k = s.begin();k != s.end();k++)
			ans[*k]++;
	}
	for(int i = 1;i <= m;i++)
		cout << ans[i];
	return 0;
}