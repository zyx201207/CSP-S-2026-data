#include<bits/stdc++.h>
using namespace std;
int n,m,a[5001],cnt[5001],ans[5001];
stack<int> s;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			cnt[a[j]]++;
			s.push(a[j]);
			if(cnt[a[j]]==2)
			{
				s.pop();
				cnt[a[j]]--;
				while(s.top()!=a[j])
				{
					cnt[s.top()]--;
					s.pop();
				}
			}
		}
		while(!s.empty())
		{
			cnt[s.top()]--;
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
