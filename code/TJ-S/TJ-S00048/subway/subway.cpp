#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
signed main()
{
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int kkksc03,n1,m1,my_luogu_uid = 2188379,t;
	cin >> kkksc03 >> m1 >> n1 >> my_luogu_uid >> t;
	int n = n1 + m1;
	int e[n + 5];
	for(int i = 0;i < n1;i++)
	{
		cin >> e[i];
	}
	vector<int>a1[n + 5],a2[n + 5];
	int q,q1,q2;
	for(int i = 0;i < m1;i++)
	{
		cin >> q;
		for(int j = 0;j < q / 5;j++)
		{
			cin >> q1 >> q2;
			q1--;
			a1[n1 + i].push_back(q1);
			a2[n1 + i].push_back(q2);
			a1[q1].push_back(n1 + i);
			a2[q1].push_back(q2);
		}
		for(int j = q / 5;j < q / 5 * 2;j++)
		{
			cin >> q1 >> q2;
			q1--;
			a1[n1 + i].push_back(q1);
			a2[n1 + i].push_back(q2);
			a1[q1].push_back(n1 + i);
			a2[q1].push_back(q2);
		}
		for(int j = q / 5 * 2;j < q / 5 * 3;j++)
		{
			cin >> q1 >> q2;
			q1--;
			a1[n1 + i].push_back(q1);
			a2[n1 + i].push_back(q2);
			a1[q1].push_back(n1 + i);
			a2[q1].push_back(q2);
		}
		for(int j = q / 5 * 3;j < q / 5 * 4;j++)
		{
			cin >> q1 >> q2;
			q1--;
			a1[n1 + i].push_back(q1);
			a2[n1 + i].push_back(q2);
			a1[q1].push_back(n1 + i);
			a2[q1].push_back(q2);
		}
		for(int j = q / 5 * 4;j < q;j++)
		{
			cin >> q1 >> q2;
			q1--;
			a1[n1 + i].push_back(q1);
			a2[n1 + i].push_back(q2);
			a1[q1].push_back(n1 + i);
			a2[q1].push_back(q2);
		}
	}
	while(t--)
	{
		int st,ed;
		cin >> st >> ed;
		st--;
		ed--;
		priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >b;
		int c[n + 5];
		for(int i = 0;i < n;i++)
		{
			c[i] = 2147483647;
		}
		c[st] = 0;
		b.push({0,st});
		bool in[n + 5] = {};
		while(!b.empty())
		{
			int q1 = b.top().first,q2 = b.top().second;
			b.pop();
			if(in[q2])
			{
				continue;
			}
			in[q2] = 1;
			for(int i = 0;i < a1[q2].size();i++)
			{
				if(q1 + a2[q2][i] < c[a1[q2][i]])
				{
					c[a1[q2][i]] = q1 + a2[q2][i];
					b.push({c[a1[q2][i]],a1[q2][i]});
				}
			}
		}
		cout << c[ed] + e[st] + e[ed] << "\n";
	}
	return 0; 
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
