#include<bits/stdc++.h>
using namespace std;

int n,m,a[500005],b[300005];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	queue<int>q;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			bool flag=true;
			int d=q.size();
			for(int k=1;k<=d;k++)
			{
				int c=q.front();
			    q.pop();
			    if(c==a[j])
					flag=false;
			    if(flag==false) continue;
				q.push(c);
			}
			q.push(a[j]);
		}
		while(!q.empty())
		{
			int c=q.front();
			q.pop();
			b[c]++;
		}
	}
	for(int i=1;i<=m;i++)
	    cout<<b[i]<<" ";
	return 0;
} 
