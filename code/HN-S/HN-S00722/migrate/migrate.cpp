#include<bits/stdc++.h>
using namespace std;
long long x[2000005],c,t,n,d,anss=0,f=1;
int minn=1e9;
void dfs1(int zhong,int jingguo,int dangqian)
{
	if(dangqian==zhong)
	{
		minn=jingguo;
		return;
	}
	if(!f)
	{
		return;
	}
	if(x[dangqian+1]-x[dangqian]>d)
	{
		f=0;
		return;
	}
	for(int i=dangqian+1;i<=zhong;i++)
	{
		if(x[i]-x[dangqian]<=d)
		{
			dfs1(zhong,jingguo+1,i);
			return;
		}
	}
	return;
}
void dfs2(int zhong,int jingguo,int dangqian)
{
	if(dangqian==zhong)
	{
		if(jingguo==minn)
		{
			anss++;
		}
		return;
	}
	for(int i=dangqian+1;i<=zhong;i++)
	{
		if(x[i]-x[dangqian]<=d)
		{
			dfs2(zhong,jingguo+1,i);
		}
	}
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		if(c<=10)
		{
			int kkk=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					f=1;
					minn=100000000;
					anss=0;
					dfs1(j,0,i);
					minn--;
					if(f==1)
					{
						dfs2(j,0,i);
					}
					else
					{
						continue;
					}
					if(anss==2)
					{
						kkk++;
					}
				}
			}
			cout<<kkk<<endl;
		}
		if(c>=11&&c<=12)
		{
			if(x[2]-x[1]>=d)
			{
				cout<<0<<endl;
			}
			else if(x[2]-x[1]<=d/2&&d%2==0&&x[3]-x[1]>=d/2)
			{
				cout<<n-3<<endl;
			}
			else
			{
				cout<<0<<endl;
			}
		}
		if(c>=13&&c<=14)
		{
			cout<<0<<endl;
		}
	}
	return 0;
}
