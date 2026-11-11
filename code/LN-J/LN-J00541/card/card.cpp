#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int N=5e5+10;
int a[N];
int vis[N],v[N];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	int k=n;
	int f=m;
	while(n>0)
	{
		for(int i=1;i<=n;i++)
		{
			vis[i]=0;
		}
		stack<int>st;
		for(int i=k-n+1;i<=n;i++)
		{
			if(vis[i]==0)
			{
				st.push(a[i]);
				if(a[i]==f-m+1)
				{
					vis[i]++;
				}
			}
			else
			{
				while(!st.empty())
				{
					st.pop();
				}
				memset(vis,0,sizeof vis);
			}
		}
		n--;
		m--;
		for(int i=1;i<=m;i++)
		{
			v[i]+=vis[i];
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout << v[i] << " ";
	}
	return 0;
}
