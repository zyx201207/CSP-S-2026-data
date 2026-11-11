#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500100],vis[500100],cnt[500100];
int main()
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
		stack<int> b;
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]]==0)
			{
				b.push(a[j]);
				vis[a[j]]=b.size();
			}
			else
			{		
				int len=b.size()-vis[a[j]]+1;
				for(int c=1;c<=len;c++)
				{
					vis[b.top()]=0;
					b.pop();
				}
				b.push(a[j]);
				vis[a[j]]=b.size();
			}
		}
		while(!b.empty())
		{
			
			cnt[b.top()]++;
//			cout<<i<<" "<<b.top()<<endl;
			b.pop();
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
	}
	return 0;
}

