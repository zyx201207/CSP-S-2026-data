#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[500005];
int ans[500005];
int s[500005];
int last[500005];
int t[500005];

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if(n * n <= 1e9)
	{
		for(int i = 1;i <= n;i++)
		{
			int head = 0;
			for(int j = i;j <= n;j++)
			{
				if(last[a[j]] == 0)
				{
					last[a[j]] = 1;
					s[++head] = j;
				}
				else
				{
					while(a[s[head]] != a[j])
					{
						last[a[s[head]]] = 0;
						head--;
					}
				}
			}
			for(int j = 1;j <= head;j++)
			{
				ans[a[s[j]]]++;
				last[a[s[j]]] = 0;
			}
		}
		for(int i = 1;i <= m;i++)
		{
			cout << ans[i] << ' ';
		}
	}
	else
	{
		int head = n + 1;
		for(int i = n;i >= 1;i--)
		{
			if(last[a[i]] == 0)
			{
				last[a[i]] = i;
				s[--head] = i;
				t[a[i]] = i;
			}
			else
			{
				while(a[s[head]] != a[i])
				{
					ans[a[s[head]]] += t[a[s[head]]] - i;
					last[a[s[head]]] = 0;
					t[a[s[head]]] = 0;
					head++;
				}
			}
		}
		for(int i = head;i <= n;i++)
		{
			ans[a[s[i]]] += t[a[s[i]]];
		}
		for(int i = 1;i <= m;i++)
		{
			cout << ans[i] << ' ';
		}
	}
	return 0;
}