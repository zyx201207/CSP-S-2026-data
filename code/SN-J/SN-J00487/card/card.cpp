#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[200005]={};
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	stack<int>s;
	int ans[200005]={};
	for(int i=1;i<=n;i++)
	{
		bool b[200005]={};
		for(int j=i;j<=n;j++)
		{
			if(b[a[j]]==0)
			{
				s.push(a[j]);
				b[a[j]]=1;
			}
			else
			{
				while(s.top()!=a[j])
				{
					b[s.top()]=0;
					s.pop();
				}
			}
		}
		for(int j=1;j<=m;j++)
		{
			ans[j]+=b[j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
