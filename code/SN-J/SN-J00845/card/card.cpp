// 欧阳宁佑 SN-J00845 西安市铁一中学 
#include<bits/stdc++.h>
using namespace std;
int n,m,a[510],ans[510],vis[510];
stack<int>st;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof vis);
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]])
			{
				while(st.top()!=a[j])
				{
					vis[st.top()]=0;
					st.pop();
				}
				vis[a[j]]=1;
			}
			else st.push(a[j]),vis[a[j]]=1;
		}
		while(!st.empty()) ans[st.top()]++,st.pop();
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
