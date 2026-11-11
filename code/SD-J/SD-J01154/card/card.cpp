#include <bits/stdc++.h>
#define ll long long
#define TIE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
bool f[300005];
int n,m,g[500005],a[300005];
stack<int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	TIE
	memset(f,true,sizeof(f));
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		memset(f,true,sizeof(f));		
		for (int j = i; j <= n; j++)
		{
			if (f[a[j]])
			{
				s.push(a[j]);
				f[a[j]] = false;
			}
			else
			{
				while (s.top() != a[j])
				{
					f[s.top()] = true;
					s.pop();
				}
			}
		}
		for (int j = 1; j <= m; j++)
		{
			if (!f[j]) g[j]++;
		}
		while (!s.empty()) s.pop();
	}
	for (int i = 1; i <= m; i++)
	{
		cout << g[i] << " ";
	}
	return 0;
} 
