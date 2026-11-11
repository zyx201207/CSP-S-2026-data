#include<bits/stdc++.h>
using namespace std;
int n;
long long num = 0;
struct point
{
	int cnt;
	char c;
}s[200010];
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> s[i].cnt >> s[i].c;
	int f = 1, e = n;
	while(f < e)
	{
		if(s[f].c != s[e].c)
		{
			if(s[f].cnt < s[e].cnt)
			{
				num += s[f].cnt;
				s[e].cnt -= s[f].cnt;
				f++;
			}
			else if(s[f].cnt == s[e].cnt)
			{
				num += s[f].cnt;
				f++;
				e--;
			}
			else if(s[f].cnt > s[e].cnt)
			{
				num += s[e].cnt;
				s[f].cnt -= s[e].cnt;
				e--;
			}
		}
		else
		{
			if(s[f].cnt < s[e].cnt)
			{
				s[e].cnt -= s[f].cnt;
				f++;
			}
			else if(s[f].cnt == s[e].cnt)
			{
				f++;
				e--;
			}
			else
			{
				s[f].cnt -= s[e].cnt;
				e--;
			}
		}
	}
	cout << num;
	return 0;
} 
