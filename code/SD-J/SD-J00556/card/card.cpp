#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr ll N = 5e3 + 7;
ll A[N];
ll book[N];
stack<ll> S;
ll ans[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	scanf("%lld%lld",&n,&m);
	for (ll i = 1; i <= n; i ++)
	{
		scanf("%lld",&A[i]);
	}
	for (ll i = 1; i <= n; i ++)
	{
		for (ll j = i; j <= n; j ++)
		{
			if (book[A[j]])
			{
				while (S.top() != A[j])
				{
					book[S.top()] = 0;
					S.pop();
				}
				S.pop();
				book[A[j]] = 0;
			}
			S.push(A[j]);
			book[A[j]] = 1;
		}
		while (S.size())
		{
			ll t = S.top();
			S.pop();
			ans[t] ++;
			book[t] = 0;
		}
	}
	for (ll i = 1; i <= m; i ++) printf("%lld ",ans[i]);
	return 0;
}

