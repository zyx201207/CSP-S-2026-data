#include<bits/stdc++.h>
using namespace std;
bool ip1,ip2,ip;
long long a[2000010],n,c,t,d,ans,cnt,sum;
long long read()
{
	long long x=0,f=1;
	char ch=getchar();
	while((ch>'9'||ch<'0')&&ch!='-')
	{
		ch=getchar();
	}
	if(ch=='-')
	{
		f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0')
	{
		x=x*10+int(ch-'0');
		ch=getchar();
	}
	return x*f;
}
void dfs(int x,int y,int z)
{
	if(ans<z)return;
	else if(x==y)
	{
		if(ans==z)cnt++;
		else if(ans>z)
		{
			ans=z;
			cnt=1;
		}
	}
	for(int i=y;i>=x+1;i--)
	{
		if(a[i]-a[x]<=d)
		{
			dfs(i,y,z+1);
			if(i>x+1)dfs(i-1,y,z+1);
			break;
		}
	}
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();
	t=read();
	while(t--)
	{
		n=read();
		d=read();
		sum=0;
		if(n<4)
		{
			cout<<0<<"\n";
		}
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+3;j<=n;j++)
			{
				ans=n+1;
				cnt=0;
				dfs(i,j,0);
				if(cnt==2)sum++;
				if(cnt==0)break;
			}
		}
		printf("%lld\n",sum);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

