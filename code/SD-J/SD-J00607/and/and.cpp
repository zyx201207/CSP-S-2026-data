#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int n, m;
int a[N];
int mx[N];
map<int,int> c;
bool flag = 0;
int pf7 = 0x3f3f3f3f, maxn = -1;
int pf16[5];

int count1(int n)
{
	int i = 0, ans = 0;
	while (n <= (1 << i))
	{
		if (n & (1 << i))
		{
			ans++;
		}
		i++;
	}
	return ans;
}

bool comp(int a, int b)
{
	if (count1(a) != count1(b))
		return count1(a) > count1(b);
	else 
		return a > b;
}

bool down(int a, int b)
{
	return a > b;
}

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		c[a[i]] = count1(a[i]);
		float lg = log2(a[i] + 1);
		if (lg != floor(lg)) flag = 1;

		maxn = max(maxn, a[i]);
		pf7 &= a[i];
		
		if (a[i] <= 3)
		{
			pf16[a[i]]++;
		}
	}
	
	if (m == n)
	{
		cout << pf7;
		return 0;
	}
	
	if (m == 1)
	{
		cout << maxn;
		return 0;
	}
	
	if (!flag)
	{
		sort(a+1, a+n+1, down);
		cout << a[m];
		return 0;
	}
	
	if (maxn < 4)
	{
		for (int i = 3; i > 0; i--)
		{
			pf16[i] += pf16[i+1];
			if (pf16[i] >= m)
			{
				cout << i;
				return 0;
			}
		}
		cout << 0;
		return 0;
	}
	
	sort(a+1, a+n+1, comp);
	
	mx[0] = 0x3f3f3f3f;
	for (int i = 1; i <= n; i++ )
	{
		for (int j = min(i, m); j >= 1; j--)
		{
			mx[j] = max(mx[j], mx[j-1] & a[i]);
		}
	}
	
	cout << mx[m];
	return 0; 
}

