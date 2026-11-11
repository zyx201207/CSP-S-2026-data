#include <bits/stdc++.h>
using namespace std;
const int N=5e5+12,M=3e5+12;
stack<int> s;
bool A=true;
int n,m,a[N],used[M],cnt[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1])
		{
			A=false;
		}
	}
	if(A==true)
	{
		for(int i=1;i<=n;i++)
		{
			cnt[a[i]]++;
		}
		for(int i=1;i<=m;i++)
		{
			cnt[i]+=cnt[i-1];
		}
		for(int i=1;i<=m;i++)
		{
			cout<<cnt[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			used[j]=0;
		}
		for(int j=i;j<=n;j++)
		{
			if(used[a[j]]==0)
			{
				s.push(a[j]);
				used[a[j]]=1;
			}
			else
			{
				while(s.top()!=a[j])
				{
					used[s.top()]=0;
					s.pop();
				}
			}
		}
		while(!s.empty())
		{
			cnt[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
	}
	return 0;
}
