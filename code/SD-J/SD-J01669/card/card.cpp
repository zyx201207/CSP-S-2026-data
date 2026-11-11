#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e5+5;
stack<int>st;
int cnt[N],ans[5005][5005],a[N];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(cnt[a[j]]==0)
			{
				st.push(a[j]);
				cnt[a[j]]=1;
			}
			else
			{
				while(st.top()!=a[j])
				{
					st.pop();
				}
				st.pop();
				memset(cnt,0,sizeof(cnt));
				st.push(a[j]);
				cnt[a[j]]=1;
			}
		}
		while(!st.empty())
		{
			ans[i][st.top()]=1;
			st.pop();
		}
		memset(cnt,0,sizeof(cnt));
	}
	for(int i=1;i<=m;i++)
	{
		int sum=0;
		for(int j=1;j<=n;j++)
		{
			sum+=ans[j][i];
		}
		cout<<sum<<" ";
	}
	return 0;
}
