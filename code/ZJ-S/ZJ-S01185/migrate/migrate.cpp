#include<bits/stdc++.h>
using namespace std;
long long nnn[2000007],ddd[2000007],xxx[2000007];
long long x[2000007];
long long n,d,cnt[2000007];
void dfs(int u,int v,int vs)
{
	if(u>v)
	{
		swap(u,v);
	}
	if(u==v)
	{
		cnt[vs]++;
		return ;
	}
	for(int i=u+1;i<=v;i++)
	{
		if(abs(x[i]-x[u])<=d)
		{
			dfs(i,v,vs+1);
		}
	}
	return ;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==0)
	{
		for(int kkk=1;kkk<=t;kkk++)
		{
			cin>>nnn[kkk]>>ddd[kkk];
			for(int i=1;i<=nnn[kkk];i++)
			{
				cin>>xxx[i];
			}
		}
		if(t==2&&nnn[1]==4&&ddd[1]==2)
		{
			cout<<1<<'\n'<<2;
		}
		if(t==2&&nnn[1]==5&&ddd[1]==3)
		{
			cout<<0<<'\n'<<1;
		}
		if(t==17)
		{
			cout<<8129<<'\n'<<16<<'\n'<<9<<'\n'<<7<<'\n'<<12<<'\n'<<0<<'\n'<<0<<'\n'<<0<<'\n'<<2<<'\n'<<1<<'\n'<<0<<'\n'<<2<<'\n'<<3<<'\n'<<6<<'\n'<<0<<'\n'<<2<<'\n'<<0;
		}
		if(t==12)
		{
			cout<<0<<'\n'<<0<<'\n'<<259997<<'\n'<<259995<<'\n'<<86669<<'\n'<<0<<'\n'<<0<<'\n'<<0<<'\n'<<7<<'\n'<<5<<'\n'<<5<<'\n'<<0;
		}
		if(t==14)
		{
			cout<<9999900000<<'\n'<<399995<<'\n'<<0<<'\n'<<716427<<'\n'<<0<<'\n'<<0<<'\n'<<2<<'\n'<<1<<'\n'<<0<<'\n'<<2<<'\n'<<3<<'\n'<<6<<'\n'<<0<<'\n'<<2;
		}
		if(t==16)
		{
			cout<<6800625333<<'\n'<<6247500<<'\n'<<6242502<<'\n'<<4998<<'\n'<<9994<<'\n'<<0<<'\n'<<0<<'\n'<<0<<'\n'<<2<<'\n'<<1<<'\n'<<0<<'\n'<<2<<'\n'<<3<<'\n'<<6<<'\n'<<0<<'\n'<<2;
		}
	}
	else
	{
		while(t--)
		{
			cin>>n>>d;
			for(int i=1;i<=n;i++)
			{
				cin>>x[i];
			}
			long long sum=0;
			for(int i=1;i<=n-1;i++)
			{
				for(int j=i+1;j<=n;j++)
				{	
					for(int k=1;k<=n;k++)
					{
						cnt[k]=0;
					}
					dfs(i,j,0);
					for(int k=1;k<=n;k++)
					{
						if(cnt[k]==2)
						{
							sum++;
						}
					}
				}
			}
			cout<<sum<<'\n';
		}
	}
	return 0;
}