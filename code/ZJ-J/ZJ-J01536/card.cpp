#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005]={},vis[300005]={},b[300005]={};
int main()
{
	//freopen("card1.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		vector<int>q;
		for(int j=i;j<=n;j++)
		{
			if(!vis[a[j]])
			{
				q.push_back(a[j]);
				vis[a[j]]=1;
			}
			else
			{
				while(q.back()!=a[j])
				{
					q.pop_back();
				}
				q.pop_back();
				q.push_back(a[j]);
				vis[a[j]]=1;
			}
		}
		int x=q.size();
		while(x)
		{
			b[q[x+1]]++;
			//cout<<q[x];
			x--;
		}
	}
	for(int i=1;i<=m;i++)
	{
    	cout<<b[i]<<" ";
    }
    cout<<1;
	return 0;
}