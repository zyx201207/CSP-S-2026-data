#include<bits/stdc++.h>
using namespace std;
vector<int>a,cnt;
vector<int>now;
int find(int x)
{
	for(int i=0;i<now.size();i++)
	{
		if(x==now[i])
		{
			return i;
		}
	}
	return -1;
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cnt.resize(m+1,0);
	a.resize(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(now.empty())
			{
				now.push_back(a[j]);
				continue;
			}
			int found=find(a[j]);
			if(found==-1)
			{
				now.push_back(a[j]);
			}
			else
			{
				while(now.back()!=a[j])
				{
					now.pop_back();
				}
			}
		}
		for(int j=0;j<now.size();j++)
		{
			cnt[now[j]]++;
		}
		now.clear();
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
	}
	return 0;
}
