#include <bits/stdc++.h>
using namespace std;

int n;
char c[200005];
long long a[200005], re, sum, cnt, goal;


int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    
    cin >> n;
    
    for (int i = 1; i <= n; i++)
    {
    	cin >> a[i] >> c[i];
    	sum += a[i];
	}

	goal = sum / 2;
	int l = 1, r = n;
	while (true)
	{
		int x = min(a[r], a[l]);
		
		if (c[l] != c[r])
		{
			re += min(a[r], a[l]);
		}
		
		a[l] -= x;
		a[r] -= x;
		cnt += x;
		if (a[l] == 0)
		{
			l++;
		}
		if (a[r] == 0)
		{
			r--;
		}
		
		if ((l == r) || (cnt >= goal))
		{
			break;
		}
	}
	cout << re;
    return 0;
}
