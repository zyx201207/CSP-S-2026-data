#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010],mx,l[200010],r[200010];
int ch[1000010][3],tot,b[100],cnt[1000010];
void add(int x,int y)
{
	if(!ch[x][b[y]])
	{
		ch[x][b[y]]=++tot;
	}
	if(y==0)
	{
		cnt[ch[x][b[y]]]++;
		if(b[y]==1)
		{
			if(!ch[x][0])
			{
				ch[x][0]=++tot;
			}
			cnt[ch[x][0]]++;
		}
		return;
	}
	cnt[ch[x][b[y]]]++;
	add(ch[x][b[y]],y-1);
	if(b[y]==1)
	{
		if(!ch[x][0])
		{
			ch[x][0]=++tot;
		}
		cnt[ch[x][0]]++;
		add(ch[x][0],y-1);
	}
	return;
}
long long ask()
{
	int p=0;
	long long ret=0;
	for(int i=30;i>=0;i--)
	{
		if(ch[p][1]!=0&&cnt[ch[p][1]]>=m)
		{
			ret+=(1<<i);
			p=ch[p][1];
		}
		else if(ch[p][0]!=0)
		{
			p=ch[p][0];
		}
		else
		{
			break;
		}
	}
	return ret;
}
void dfs(int x,int y,long long s)
{
	if(y>m)
	{
		return;
	}
	if(x==n+1)
	{
		if(y==m)
		{
			mx=max(mx,s);
		}
		return;
	}
	if(s==-1)
	{
		dfs(x+1,y+1,a[x]);
	}
	else
	{
		dfs(x+1,y+1,s&a[x]);
	}
	dfs(x+1,y,s);
}
bool check()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=30;j>=0;j--)
		{
			if(a[i]!=((1ll<<j)-1))
			{
				return 0;
			}
		}
	}
	return 1;
}
int main()
{
	//freopen("dayangli.cpp","r",stdin);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	if(n<=20)
	{
		dfs(1,0,-1);
		cout<<mx;
		return 0;
	}
	if(n<=2000)
	{
		if(m==1)
		{
			long long mx2=0;
			for(int i=1;i<=n;i++)
			{
				mx2=max(mx2,a[i]);
			}
			cout<<mx2;
		}
		else if(m==2)
		{
			long long mx2=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					mx2=max(mx2,a[i]&a[j]);
				}
			}
			cout<<mx2;
		}
		else
		{
			long long mx2=a[1];
			for(int i=2;i<=n;i++)
			{
				mx2&=a[i];
			}
			cout<<mx2;
		}
		return 0;
	}
	if(m==n-1)
	{
		l[1]=a[1];
		r[n]=a[n];
		for(int i=2;i<=n;i++)
		{
			l[i]=l[i-1]&a[i];
		}
		for(int i=n-1;i>=1;i--)
		{
			r[i]=r[i+1]&a[i];
		}
		long long mx2=max(l[n-1],r[2]);
		for(int i=2;i<=n-1;i++)
		{
			mx2=max(mx2,l[i-1]&r[i+1]);
		}
		cout<<mx2;
		return 0;
	}
	if(check())
	{
		sort(a+1,a+1+n);
		long long mx2=a[n];
		for(int i=n-1;i>=n-m+1;i--)
		{
			mx2=mx2&a[i];
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=30;j>=0;j--)
		{
			if((1ll<<j)&a[i])
			{
				b[j]=1;
			}
			else
			{
				b[j]=0;
			}
		}
		add(0,30);
	}
	printf("%lld",ask());
	return 0;
}
