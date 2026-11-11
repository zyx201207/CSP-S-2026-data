#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,m;
	if(!(cin>>n>>m)) return 0;
	
	vector<int> a(n + 1);
	for(int i = 1;i <= n;++i)
	{
		cin>>a[i];
	}
	
	vector<int> ans(m+1,0);
	vector<int> start(m+1,0);
	
	list<int> S;
	
	vector<list<int>::iterator> pos(m + 1,S.end());
	for(int j = n;j >= 1;--j)
	{
		int x = a[j];
		if(pos[x] != S.end())
		{
			auto it = pos[x];
			while(it != S.end())
			{
				int y = *it;
				ans[y] += start[y] - j;
				pos[y] = S.end();
				it = S.erase(it);
			}
		}
		S.push_back(x);
		pos[x] = --S.end();
		start[x] = j;
	}
	
	for(int y:S)
	{
		ans[y] += start[y];
	}
	for(int i = 1;i<=m;++i)
	{
		if(i > 1)
			cout<<" ";
		cout<<ans[i];
	}
	cout<<"\n";
	
	return 0;
}
