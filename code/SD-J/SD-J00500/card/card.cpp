#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	int x=0,y=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')y=-1;c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*y;
}
const int N=2e5+7;
int n,m;

bool vis[N];
int a[N];
int ans[N];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	if(m<=2&&n>=100)
	{
		for(int st=1;st<=n;st++)
		{
			if(a[st]==a[n])ans[a[st]]++;
			else ans[a[st]]++,ans[a[n]]++;
		}
		for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
		return 0;
	}
	for(int st=1;st<=n;st++)
	{
		stack<int>s;
		for(int j=st;j<=n;j++)
		{
			if(!vis[a[j]])s.push(a[j]),vis[a[j]]=1;
			else
			{
				while(1)
				{
					vis[s.top()]=0;
					if(s.top()==a[j])
					{
						vis[s.top()]=1;
						break;
					}
					s.pop();
				}
			}

		}
		for(int i=1;i<=m;i++)
		{
			if(vis[i])ans[i]+=vis[i];
			vis[i]=0;
		} 
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	
	return 0;
}
