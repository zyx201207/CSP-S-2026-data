#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N = 5e5 + 10;
int n,m;
int a[N],vis[N],ans[N];
int lst[N];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	if(n <= 5000) 
	{
		stack<int> st;
		for(int i = 1; i <= n; i++)
		{
			memset(vis,0,sizeof vis);
			for(int j = i; j <= n; j++)
			{
				if(vis[a[j]] == 1) {
					while(!st.empty())
					{
						int t = st.top();
						vis[t] = 0;
						st.pop();
						if(t == a[j]) break;
					}
				}
				st.push(a[j]);
				vis[a[j]] = 1;
			}
			while(!st.empty())
			{
				ans[st.top()]++;
				st.pop();
			}
		}
		for(int i = 1; i <= m; i++)
			cout << ans[i] << " ";
	}else 
	{
		for(int i = 1; i <= n; i++)
			lst[a[i]] = i;
		for(int i = 1; i <= m; i++)
			cout << lst[i] << " ";
	}
	return 0;
}
