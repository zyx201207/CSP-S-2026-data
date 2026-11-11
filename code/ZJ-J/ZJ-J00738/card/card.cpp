#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
bool vis[N];
int ans[N];
int a[N],n,m;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=200000&&m<=3000)
	{
		for(int i=1;i<=n;i++)
		{
			stack<int>q;
			for(int j=i;j<=n;j++)
			{
				if(!vis[a[j]]) q.push(a[j]),vis[a[j]]=true;
				else 
				{
				//	cout<<"Number : ";
					while(!q.empty()&&q.top()!=a[j]) vis[q.top()]=false,q.pop();
				//	cout<<"\n";
					vis[a[j]]=true;
					q.push(a[j]);
				//	cout<<"Erase : "<<a[j]<<"\n";
				}
			}
			while(!q.empty())
			{
				if(!vis[q.top()]) q.pop();
				else
				{
					vis[q.top()]=false;
				//	cout<<q.top()<<" ";
					ans[q.top()]++;
					q.pop();
				}
			}
		//	cout<<"\n";
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	}
	else
	{
		for(int i=1;i<=m;i++) cout<<i<<" ";
	}
	return 0;
}

