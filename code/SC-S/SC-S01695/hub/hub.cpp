#include <bits/stdc++.h>
using namespace std;
int n,u,v,k,c,t,f[1000010],k1,sum,num=1e9;
bool b[1000010];
queue<int> q;
void bfs()
{
	int ost=0;
	while(!q.empty())
	{
		int st=q.front();
		b[st]=1;
		if(f[st]==ost) sum++;
		for(int i=1;i<=n;i++)
		{
			if(f[i]==st&&!b[i]&&k1)
			{
				k1--;
				q.push(i);
			}
		}
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			cin>>u>>v;
			f[u]=v;
			f[v]=u;
		}
		
		for(int i=1;i<=n;i++)
		{
			k1=k;
			q.push(i);
			bfs();
			num=min(num,sum);
			sum=0;
		}
	}
	cout<<num;
	return 0;
}