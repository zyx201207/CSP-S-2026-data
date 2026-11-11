//zhoujingzhi 西安交通大学附属中学 SN-J00676 
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e5 + 10;

int n;

struct node
{
	int v;
	char c;
	
} a[MAXN];

pair<int, char> lefts[MAXN];
pair<int, char> rights[MAXN];

int pre[MAXN];

signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	
	int L = 0;
	
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i].v >> a[i].c;
		
		L += a[i].v;
		pre[i] = pre[i - 1] + a[i].v;
	}
	
	if (L % 2 == 1)
	{
		int f = L / 2 + 1;
		
		int m = 0;
		
		for (int i = 1; i <= n; ++i)
		{
			if (pre[i] >= f)
			{
				m = i;
				break;
			}
		}
		
		for (int i = 1; i < m; ++i)
		{
			lefts[i].first = a[i].v;
			lefts[i].second = a[i].c;
		}
		lefts[m].first = f - pre[m - 1] - 1;
		lefts[m].second = a[m].c;
		
		for (int i = n; i > m; --i)
		{
			rights[n - i + 1].first = a[i].v;
			rights[n - i + 1].second = a[i].c;
		}
		rights[n - m + 1].first = pre[m] - f;
		rights[n - m + 1].second = a[m].c;
		
		//
		int ans = 0;
		int lc = lefts[1].second, rc = rights[1].second;
		int al = 1, ar = 1;
		
		while (al <= m && ar <= L - m + 1)
		{
			if (lefts[al].first > rights[ar].first)
			{
				if (lc != rc) ans += rights[ar].first;
				
				lefts[al].first -= rights[ar].first;
				++ar;
				rc = rights[ar].second;
			}
			else if (lefts[al].first < rights[ar].first)
			{
				if (lc != rc) ans += lefts[al].first;
				rights[ar].second -= lefts[al].second;
				++al;
				lc = lefts[al].second;
			}
			else if (lefts[al].first == rights[ar].first)
			{
				if (lc != rc) ans += lefts[al].first;
				++al, ++ar;
				lc = lefts[al].second;
				rc = rights[ar].second;
			}
		}
		
		cout << ans << endl;
	}
	else
	{
		int f = L / 2;
		
		int m = 0;
		
		for (int i = 1; i <= n; ++i)
		{
			if (pre[i] >= f)
			{
				m = i;
				break;
			}
		}
		
		for (int i = 1; i < m; ++i)
		{
			lefts[i].first = a[i].v;
			lefts[i].second = a[i].c;
		}
		lefts[m].first = f - pre[m - 1];
		lefts[m].second = a[m].c;
		
		for (int i = n; i > m; --i)
		{
			rights[n - i + 1].first = a[i].v;
			rights[n - i + 1].second = a[i].c;
		}
		rights[n - m + 1].first = pre[m] - f;
		rights[n - m + 1].second = a[m].c;
		
		//
		int ans = 0;
		int lc = lefts[1].second, rc = rights[1].second;
		int al = 1, ar = 1;
		
		while (al <= m && ar <= L - m + 1)
		{
			if (lefts[al].first > rights[ar].first)
			{
				if (lc != rc) ans += rights[ar].first;
				
				lefts[al].first -= rights[ar].first;
				++ar;
				rc = rights[ar].second;
			}
			else if (lefts[al].first < rights[ar].first)
			{
				if (lc != rc) ans += lefts[al].first;
				rights[ar].second -= lefts[al].second;
				++al;
				lc = lefts[al].second;
			}
			else if (lefts[al].first == rights[ar].first)
			{
				if (lc != rc) ans += lefts[al].first;
				++al, ++ar;
				lc = lefts[al].second;
				rc = rights[ar].second;
			}
		}
		
		cout << ans << endl;
	}
	
	return 0;
}

