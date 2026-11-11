#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
struct Node{
	int next;
};
Node p[300010];
int n,m,a[300010],t[300010],f[300010],ans[300010];
vector<int> v[300010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		v[a[i]].push_back(i);
	}
	if(n==m)
	{
		for(int i=1;i<=m;i++)
		{
			cout<<v[i][0]<<' ';
		}
		return 0;
	}
	p[n].next=n+1;
	for(int i=1;i<=n;i++)
	{
		memset(t,0,sizeof(t));
		memset(f,0,sizeof(f));
		for(int j=i;j<=n+1;j++)
		{
			p[j-1].next=j;
		}
		int j=i;
		while(j<=n)
		{
			if(t[a[j]])
			{
				p[f[a[j]]].next=j+1;
			}
			else
			{
				f[a[j]]=j;
			}
			t[a[j]]=1;
			j=p[j].next;
		}
		j=i;
		while(j<=n)
		{
			ans[a[j]]++;
			j=p[j].next;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}