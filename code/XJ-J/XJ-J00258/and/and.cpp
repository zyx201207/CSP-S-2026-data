#include<bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 7;
int n,m,a[N];
string ar[N],an = "";
int ans,temp,len;
string pr(int n)
{
	string s = "";
	while(n > 0)
	{
		s += n % 2 + '0';
		n / 2;
	}
	return s;
}
int pb(string n)
{
	int ans,a = 1;
	int len = n.size();
	for(int i = 0; i < len; i++)
	{
		ans += a * (n[i] - '0');
		a *= 2;
	}
	return ans;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i= 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++)
	{
		for(int j = i; j <= n; j++)
		{
			for(int te = 0; te < m; te++)
			{
				int x = te + j;
				int y = a[x];
				ar[te] = pr(y);
				int t = ar[te].size();
				if(t > len) len = t;
			}
			bool flag = 1;
			for(int te = 0; te < len; te++)
			{
				for(int c = 0; c < m; c++)
				{
					int t = c + 1;
					if(ar[c][te] != ar[c][te]) flag = 0;
				}
				if(flag) an += ar[1][te];
				else an +="0";
			}
			temp = pb(an);
			if(temp > ans) ans = temp;
		}
	}
	cout << ans;
	return 0;
}