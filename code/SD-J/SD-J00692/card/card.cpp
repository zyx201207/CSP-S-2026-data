#include <bits/stdc++.h>
using namespace std;
const int size = 5e5 + 5;
int n,m,k;
int a[size],b[size],ans[size];
stack <int> s;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	for(int k = 1;k <= n;k++)
	{
		memset(b,sizeof(b),0);
		for(int i = k;i <= n;i++)
		{
			s.push(a[i]);
			b[a[i]]++;
			if(b[a[i]] > 1)
			{
				b[s.top()]--;
				s.pop();
				while(s.top() != a[i] && !s.empty())
				{
					b[s.top()]--;
					s.pop();
				}
			}
		}
		while(!s.empty())
		{
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i = 1;i <= m;i++)
		cout << ans[i] << ' ';
	return 0;
}
