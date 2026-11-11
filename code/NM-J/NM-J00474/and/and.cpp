#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m;
priority_queue<ll, vector<ll>, greater<ll>> mn_pq; // xiaogendui
priority_queue<ll> mx_pq; // dagendui

void check()
{
	ll mns = mn_pq.size();
	if (mns > m)
	{
		while (mns > m)
		{
			mx_pq.push(mn_pq.top());
			mn_pq.pop();
			mns = mn_pq.size();
		}
}
}
void p(ll n)
{
	if (mn_pq.empty()) mn_pq.push(n);
	else  mn_pq.push(n);
	check();
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
	//cin >> n >> m;
	
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		ll b;
		cin >> b;
		p(b);
	}
	cout << mn_pq.top();
	//mn_pq.pop();
	//cout << endl << mn_pq.top();
    return 0;
}

