#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500050];
map<int,int>v;
int bf(int x,int g)
{
	stack<int>q;
	map<int,bool>s;
	s[a[x]] = 1;
	q.push(a[x]);
	for (int i = x + 1;i <= n;i ++)
	{
		if (s[a[i]] == 1)
		{
			while (q.size() > 0)
			{
				if (q.top() == a[i])break;
				else
				{
					s[q.top()] = 0;
					q.pop();
				}
			}
		}
		else
		{
			s[a[i]] = 1;
			q.push(a[i]);
		}
	}
	while (q.size() > 0)
	{
		if (q.top() == g)return 1;
		q.pop();
	}
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i = 1;i <= n;i ++)
	{
		cin>>a[i];
		v[a[i]] ++;
	}
//	bf(8,1);
	for (int k = 1;k <= m;k ++)
	{
		if (a[n] == k)
		{
			cout<<n<< " ";
			continue;
		}
		int ans = v[k];
		for (int i = 1;i < n;i ++)
		{
			if (a[i] == k)continue;
//			if (k == 2&&bf(i,k) == 1)cout<<i<<endl;
			ans += bf(i,k);
		}
		cout<<ans<<" ";
	}
	return 0;
}