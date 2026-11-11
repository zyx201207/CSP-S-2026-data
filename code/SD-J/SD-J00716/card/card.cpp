#include<bits/stdc++.h>
using namespace std;
const int MX=2e5;
int vis[MX+10],a[MX+10];
int leave[MX+10];
stack<int>ss;
long long n,m;
inline long long read()
{
	char ch=getchar();
	long long x=0,f=1;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	int i,j,t=1;
	for(i=1;i<=n;i++)
	{
		a[i]=read();
		if(a[i]<a[i-1])
		{
			t=0;
		}
	}
	if(t==1)
	{
		for(i=1;i<=n;i++)
		{
			memset(vis,0,sizeof(vis));
			for(j=i;j<=n;j++)
			{
				if(vis[a[j]]==1)
				{
					
				}
				else
				{
					vis[a[j]]=1;
					leave[a[j]]++;
				}
			}
		}
		for(i=1;i<=m;i++)
		{
			cout<<leave[i]<<' ';
		}
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		for(j=i;j<=n;j++)
		{
			if(vis[a[j]]==1)
			{
				while(!ss.empty()&&ss.top()!=a[j])
				{
					vis[ss.top()]=0;
					ss.pop();
				}
			}
			else
			{
				vis[a[j]]=1;
				ss.push(a[j]);
			}
		}
		while(!ss.empty())
		{
			leave[ss.top()]++;
			ss.pop();
		}
	}
	for(i=1;i<=m;i++)
	{
		cout<<leave[i]<<' ';
	}
	return 0;
}/*10 3
3 1 2 1 3 2 3 1 2 1
*/
