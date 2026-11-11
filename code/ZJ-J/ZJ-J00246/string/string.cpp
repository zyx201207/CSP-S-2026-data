#include<bits/stdc++.h>
using namespace std;
struct node
{
	char s;
	long long  t;	
}b[200010];
int n, a, len, li;
char c;
long long cnt;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a >> c;
		if(b[i - 1 - li].s == c)
		{
			b[i - 1 - li].t += a;
			li++;
		}
		else
		{
			b[i - li].s = c;
			b[i - li].t = a;
		}
	}
	int l = 1, r = n - li;
	while(l < r)
	{
		if(b[l].s != b[r].s)
		{
			if(b[l].t > b[r].t)
			{
				cnt += b[r].t;
				b[l].t -= b[r].t;
				r--;
			}
			else if(b[l].t == b[r].t)
			{
				cnt += b[l].t;
				l++;
				r--;
			}
			else
			{
				cnt += b[l].t;
				b[r].t -= b[l].t;
				l++;
			}
		}
		else
		{
			if(b[l].t > b[r].t)
			{
				b[l].t -= b[r].t;
				r--;
			}
			else if(b[l].t == b[r].t)
			{
				l++;
				r--;
			}
			else
			{
				b[r].t -= b[l].t;
				l++;
			}
		}
	}
	cout << cnt;
	return 0;
}
