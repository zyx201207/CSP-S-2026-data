#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans[N],ton[N],fl[N],cnt;
set<int> s;
deque<int> q;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(a[i]>=a[i-1]) cnt++;
	}
//	cout<<cnt;
	if(m==1)
	{
		cout<<n;
		return 0;
	}
	if(m==2&&n>5000)
	{
		for(int i=1;i<=n;i++) ans[a[i]]=max(ans[a[i]],i);
	}
	if(cnt==n)
	{
		for(int i=1;i<=n;i++)
		{
			ans[a[i]]=i;
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(s.count(a[j])==0)
				{
					s.insert(a[j]);
					q.push_back(a[j]);
				}
				else
				{
					while(q.back()!=a[j])
					{
						int x=q.back();
						q.pop_back();
						s.erase(x);
					}
				}
			}
			for(auto j:s) ans[j]++;
			s.clear();
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
