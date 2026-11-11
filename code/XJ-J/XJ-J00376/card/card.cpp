#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n, m;
vector <int> a, table;
unordered_multiset <int> st;
map <int, int> mp;
int main ()
{
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++)
	{
		int x = (scanf ("%d", &x), x);
		a.push_back (x);
	}
	while (!a.empty ())
	{
		for (int j = 0; j < a.size (); j ++)
		{
			int card = a[j];
			if (st.count (card))
			{
				while (!table.empty () && *table.end () != card)
				{
					auto del = table.end ();
					del --;
					table.pop_back ();
					st.erase (*del);
				}
			}
			st.insert (card);
			table.push_back (card);
		}
		a.erase (a.begin ());
		for (auto it : table) mp[it] ++;
		st.clear ();
		table.clear ();
	}
	for (int i = 1; i <= m; i ++) printf ("%d ", mp[i]);
	printf ("\n");
	return 0;
}