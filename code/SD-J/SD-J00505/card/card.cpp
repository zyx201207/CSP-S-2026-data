#include <bits/stdc++.h>

using namespace std;

int a[500010],ans[300010];

bool rec[300010];

stack<int> st;

signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		memset(rec,0,sizeof(rec));
		for(int j=i;j<=n;j++)
		{
			if(rec[a[j]]==0)
			{
				st.push(a[j]);
				rec[a[j]]=1;
			}
			if(rec[a[j]]==1)
			{
				while(st.top()!=a[j])
				{
					rec[st.top()]=0;
					st.pop();
				}
			}
		}
		while(!st.empty())
		{
			ans[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
