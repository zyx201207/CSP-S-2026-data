#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
stack<int> st;
int a[N];
bool v[M];
int ans[M],n,m;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int stat=1;  //start                           
	for(int i=1;i<=n;i++)
	{
		memset(v,0,sizeof(v));		
		for(int j=stat;j<=n;j++)
		{
			if(!v[a[j]]) 
			{
				st.push(a[j]);
				v[a[j]]=1;
			}
			else
			{
				while(st.top()!=a[j] && !st.empty()) 
				{
					v[st.top()]=0;
					st.pop();
				}
			}	
		}
		while(!st.empty())
		{
			ans[st.top()]++;
			st.pop();
		}
		stat++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
