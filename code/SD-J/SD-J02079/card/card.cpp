#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int P=998244353;
const int INF=0x3f3f3f3f3f3f3f3f;
const int N=1e6+10,M=2e6+10;
int n,m,a[N],col[N],ans[N];
stack<int> st;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			col[j]=0;
		}
		st.push(a[i]);
		col[a[i]]=1;
		for(int j=i+1;j<=n;j++)
		{
			if(col[a[j]]==1)
			{
				while(!st.empty())
				{
					if(st.top()==a[j])
					{
						st.pop();
						break;
					}
					else
					{
						col[st.top()]=0;
						st.pop();
					}
				}
			}
			st.push(a[j]);
			col[a[j]]=1;
		}
		while(!st.empty())
		{
			ans[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}

