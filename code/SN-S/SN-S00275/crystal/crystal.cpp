#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
	ll cnt,shu,r;
};
vector<node> v;
ll n,m;
ll a[500005];
ll s[500005];
ll maxn;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	ll cur = 0;
	ll l = 1;
	ll cnt_shu = 0;
	for (int i = 1;i <= n;i++)
	{
//		cout << l << " ";
		if (a[i] != a[i - 1] && i != 1)
		{
			v.push_back(node{cnt_shu,a[i - 1],i - 1});
			cnt_shu = 0; 
		}
		s[i] = s[i - 1] + (i - l) * (a[i] - a[i - 1]);
		if (s[i] <= m)
		{
			maxn = max(maxn,i - l + 1);
		}
		else
		{
//			cout << "i :" << i << endl;
			ll len = v.size();
			ll tot = v[len - 1].cnt;
			ll m_duo = s[i] - m;
			while(cur < len && tot >= 0 && m_duo > 0)
			{
				ll t = a[i] - v[cur].shu;
				if (m_duo <= t * (v[cur].r - l + 1))
				{
					ll d = m_duo / t;
					if (m_duo % t != 0)
					{
						d++;
					}
//					if (tot < d)
//					{
//						break;
//					}
//					tot -= d;
					l = l + d + 1;
					m_duo -= t * d;
				}
				else
				{
					l = v[cur].r + 1;
					m_duo -= t * (v[cur].r - l + 1);
//					tot -= v[cur].r - l + 1;
					cur++;
				}
			}
			s[i] = m + m_duo;
		}
		cnt_shu++;
//		cout << s[i] << " ";
//		cout << l << endl; 
	}
	for (int i = 0;i < v.size();i++)
	{
		cout << v[i].cnt << " " << v[i].shu << " " << v[i].r << endl;
	}
	cout << maxn << endl;
	return 0;
}
