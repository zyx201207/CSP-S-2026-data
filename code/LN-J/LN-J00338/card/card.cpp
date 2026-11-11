#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[500001];
bool ms[300001];
int mcount[300001];

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	stack<int> st;
	for(int i = 0; i < n; i++)
	{
		for(int j = i; j < n; j++)
		{
	
			if(ms[a[j]] == 0)
			{
				st.push(a[j]);
				ms[a[j]] = 1;
			}
			else
			{
				while(st.top() != a[j])
					st.pop();
			}
		}
		while(!st.empty())
		{
			int ss = st.top();
			st.pop();
			mcount[ss]++;
			ms[ss] = 0;
		}
	
	}
	for(int i = 1; i <= m; i++)
	{
		cout << mcount[i] << ' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
