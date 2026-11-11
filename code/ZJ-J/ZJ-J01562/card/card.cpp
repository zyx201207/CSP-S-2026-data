#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
const int M = 3e5+10;
int n,m,a[N];
map<int,int>mp;
stack<int>st;
int ans[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		mp.clear();
		for(int j = i;j <= n;j++)
		{
			if(mp[a[j]] == 0)
			{
				st.push(a[j]);
				mp[a[j]]++;
			}
			else
			{
				while(st.top() != a[j])
				{
					int t = st.top();
					st.pop();
					mp[t]--;
				}
			}
		}
		while(st.size())
		{
			int q = st.top();
			ans[q]++;
			st.pop();
		}
	}
	for(int i = 1;i <= m;i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}
