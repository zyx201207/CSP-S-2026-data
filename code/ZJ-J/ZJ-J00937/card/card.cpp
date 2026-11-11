#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500050],ans[500050],lst[500050],mx[500050];
bool vis[500050];
long long st[500050],len;
bool oka=1;
void solve1()
{
	for(long long i=1;i<=n;i++)
	{
		len=0;
		memset(vis,0,sizeof(vis));
		for(long long j=i;j<=n;j++)
		{
			if(len==0)
			{
				st[++len]=a[j];
				vis[a[j]]=1;
			}
			else
			{
				if(!vis[a[j]])
				{
					st[++len]=a[j];
					vis[a[j]]=1;
				}
				else
				{
					while(st[len]!=a[j])
					{
						vis[st[len]]=0;
						len--;
					}
					len--;
					st[++len]=a[j];
					vis[a[j]]=1;
				}
			}
		}
		while(len>0)
		{
			ans[st[len]]++;
			len--;
		}
	}
	for(long long i=1;i<=m;i++)
	{
		printf("%lld ",ans[i]);
	}
}//48pts
void solve2()
{
	for(long long i=1;i<=n-1;i++)
	{
		if(a[i]!=a[i+1])
		{
			ans[a[i]]=i;
		}
	}
	ans[m]=n;
	for(long long i=1;i<=m;i++)
	{
		printf("%lld ",ans[i]);
	}
}//4pts
void solve3()
{
	if(m==1)
	{
		cout<<n<<endl;
	}
	else
	{
		long long cnt=0;
		if(a[n]==1)
		{
			for(long long i=1;i<=n;i++)
			{
				if(a[i]==2)
				{
					cnt++;
				}
			}
			cout<<n<<" "<<cnt<<endl;
		}
		else
		{
			for(long long i=1;i<=n;i++)
			{
				if(a[i]==1)
				{
					cnt++;
				}
			}
			cout<<cnt<<" "<<n<<endl;
		}
	}
}//8pts
void solve4()
{
	long long maxx=0;
	for(long long i=1;i<=n;i++)
	{
		if(a[i]!=a[i-1])
			mx[a[i]]=i;
	}
	for(long long i=n;i>=1;i--)
	{
		if(i<mx[a[i]]&&lst[a[i]]==0)
		{
			lst[a[i]]=i+1;
			maxx=max(maxx,lst[a[i]]);
		}
	}
	for(long long i=1;i<=maxx-1;i++)
	{
		ans[a[i]]++;
	}
	for(long long i=maxx;i<=n;i++)
	{
		if(lst[a[i]]!=0||i==n) ans[a[i]]=i;
		else ans[a[i]]=i-maxx;
	}
	for(long long i=1;i<=m;i++)
	{
		printf("%lld ",ans[i]);
	}
	/*
	8:30 start
	8:31 ask teacher for something
	8:53 AC and check T1 mood+=50 sorse+=100pts
	9:14 AC and check T2 mood+=100 sorse+=100pts
	9:41 AC and check T3 modd+=200 sorse+=100pts
	9:51 don't kown how to T4 mood-=50
	9:51 eat some food ,tastes delicious! mood+=20
	10:10 do normal code to solve T4' 48pts sorse+=48pts
	10:23 do a special judge sorse+=4pts
	10:32 do a special judge sorse+=8pts
	10:35 it seems a good sorse,I must check my code
	10:44 check T1,it's ok
	10:51 check T2,it's ok
	10:54 go to bathroom, Confortable!(It better than Yuyao middle school!)
	11:02 check T3,it's ok
	11:05 continue to do T4,and I have no ideas
	11:32 write down some code sorse+=[0,40]
	11:33 lastly check
	11:36 wait and check
	*/
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1]) oka=0;
	}
	if(n<=5000&&m<=3000)
	{
		solve1();
		return 0;
	}
	else if(oka)
	{
		solve2();
		return 0;
	}
	else if(m<=2)
	{
		solve3();
		return 0;
	}
	else
	{
		solve4();
		return 0;
	}
}