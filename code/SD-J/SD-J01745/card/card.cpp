#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
bool vis[3000010];
long long cnt[300010];
long long cnt0[500010];
queue<int>q;
stack<int>st;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=k;i<=n;i++)
		 {
		 	q.push(a[i]);
		 }	
		 
		for(int i=k;i<=n;i++)
		  {
		 	int t=q.front();
			q.pop();
			if(vis[t])
			{
				while(st.top()!=t)
				{
					cnt0[st.top()]--;
				    if(cnt0[st.top()]==0)
				    {
				    	vis[st.top()]=0;
					}
					st.pop();
				}
			   st.pop();
			   cnt0[t]--;
			}
			st.push(t);
			cnt0[t]++;
			if(cnt0[t]==1)
			vis[t]=1;
		 }
		 memset(cnt0,0,sizeof(cnt0));
		 while(!st.empty())
			{
				cnt[st.top()]++;
				st.pop();
			}
		 while(!q.empty())q.pop();
		 memset(vis,0,sizeof(vis));		
	 } 
	for(int i=1;i<=m;i++)
    {
    	cout<<cnt[i]<<' '; 
	 } 
	return 0;
 } 
