#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
bool f[300005];
stack<int> s;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			while(f[a[j]]==1)
			{
				f[s.top()]=0;
				s.pop();
			}
			s.push(a[j]);
			f[a[j]]=1;
		}
		for(int j=1;j<=m;j++)
		{
			if(f[j]==1)
			{
				ans[j]++;
				f[j]=0;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
