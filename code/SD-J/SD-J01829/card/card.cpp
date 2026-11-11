#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans[300005],vis[300005];
stack<long long> st;
long long read()
{
	char ch=getchar();
	long long x=0,f=1;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		{
			f=-1;
			ch=getchar();
			break;
		}
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
	n=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]])
			{
				while(!st.empty())
				{
					if(st.top()==a[j])
					{
						st.pop();
						break;
					}
					vis[st.top()]=0;
					st.pop();
				}
				st.push(a[j]);
			}
			else
			{
				st.push(a[j]);
				vis[a[j]]=1;
			}
		}
		while(!st.empty())
		{
			ans[st.top()]++;
			st.pop();
		}
		cout<<endl;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
} 
