#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	int a[500005];
	int cnt[300005];
	stack<int> st;
	cin>>n>>m;
	for(int i = 1;i <= n;i++)
		cin>>a[i];
	for(int i = 1;i <= n;i++)
	{
		bool flag[500005];
		for(int j = 0;j <= m;j++)
            flag[j] = false;
		for(int j = i;j <= n;j++)
		{
			if(flag[a[j]] == true)
			{
				while(st.top() != a[j])
				{
					flag[st.top()] = false;
					st.pop();
				}
			}
			else
			{
				st.push(a[j]);
				flag[a[j]] = true;
			}
		}
		while(!st.empty())
		{
			cnt[st.top()]++;
			st.pop();
		}
	}
	for(int i = 1;i <= m;i++)
		cout<<cnt[i]<<" ";
	cout<<endl;
	return 0;
}
