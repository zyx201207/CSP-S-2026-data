#include<bits/stdc++.h>
using namespace std;

queue<int> card;
queue<int> table;

int find(int a)
{
	queue<int> t = table;
	int index = 0;
	while(!t.empty())
	{
		int k = t.front();
		if(k == a)
			return index;
		index++;
		t.pop();
	}
		
	return -1;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
	{
		int x;
		cin>>x;
		card.push(x);
	}
	vector<int> ans(m+1,0);
	vector<bool> used(m+1,true);
	for(int i = 1;i<=n;i++)
	{
		if(i!=1)
		{
			card.pop();
		}
		queue<int> j = card;
		while(!j.empty())
		{
			int x = j.front();
			j.pop();
			if(!used[x])
				continue;
			if(find(x)!= -1)
			{
				queue<int> l;
				int k;
				for(k = 0;k<find(x);k++)
				{
					l.push(table.front());
					table.pop();
				}
				while(!table.empty())
				{
					table.pop();
				}
				table = l;
			}
			table.push(x);
		}
		while(!table.empty())
		{
			ans[table.front()]++;
			table.pop();
		}
		used.resize(m+1,true);
	}
	for(int i = 1;i<=m;i++)
		cout<<ans[i]<<" ";
}
