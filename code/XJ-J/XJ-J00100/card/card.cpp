#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], cnt[300005];
stack<long long> s;
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(cnt[a[j]]>0)
			{
				while(s.top()!=a[j])
				{
					cnt[s.top()]--;
					s.pop();
				}
				cnt[a[j]]--;
				s.pop();
			}
			s.push(a[j]);
			cnt[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
	}
	return 0;
}
