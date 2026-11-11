#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
stack<int> st;
bool vis[300005];
int ans[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int js=1;js<=n;js++)
    {
    	memset(vis,0,sizeof(vis));
		for(int i=js;i<=n;i++)
    	{
    		if(vis[a[i]]==0) st.push(a[i]);
    		else
    		{
    			while(st.top()!=a[i])
    			{
					vis[st.top()]=0;
					st.pop();
				}
			}
			vis[a[i]]=1;
		}
		while(!st.empty())
		{
			ans[st.top()]++;
			st.pop(); 
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
//l