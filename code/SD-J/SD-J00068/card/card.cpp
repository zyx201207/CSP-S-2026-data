#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,m;
vector<int> v,d,lst,ans;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	v.resize(n+1);
	ans.resize(m+1);
	lst.resize(m+1);
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(lst[v[j]]==0)
			{
				d.push_back(v[j]);
				lst[v[j]]=1;
			}
			else
			{
				while(d.back()!=v[j])
				{
					lst[d.back()]=0;
					d.pop_back();
				}
			}
		}
		for(auto j:d)
		{
			ans[j]++;
		}
		d.clear();
		for(int j=1;j<=m;j++)
		{
			lst[j]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}
