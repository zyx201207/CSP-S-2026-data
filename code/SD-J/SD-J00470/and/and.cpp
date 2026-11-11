#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	priority_queue<ll> pq;
	for(int i = 1; i <= n; i++)
	{
		ll a;
		cin >> a;
		pq.push(a);
	}
	ll ans = pq.top();
	pq.pop();
	m--;
	while(m--)
	{
		ll c = pq.top();
		pq.pop();
		ans &= c;
	}
	cout << ans;
	return 0;
}
