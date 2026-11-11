#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t;
const int N = 200005;
struct node
{
	ll u,v;
}x[N];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while (t--)
	{
		ll n,k;
		cin >> n >> k;
		for (int i = 1;i <= n;++i)
			cin >> x[i].u >> x[i].v;
		cout << x[k].v - x[n].u << endl;
	}
	return 0;
}
