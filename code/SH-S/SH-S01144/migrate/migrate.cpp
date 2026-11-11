#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
struct node
{
	int len,num;
};
node f[5050][5050];
int x[5000050];
int t[5050];
void solve1()
{
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
	}
	node t1,t2;
	t1.len=0,t1.num=1;
	t2.num=0,t2.len=1e18;
	for(int i=1;i<=n;i++)
	{
		t[i]=i;
		f[i][i]=t1;
		for(int j=i+1;j<=n;j++)
		{
			f[i][j]=t2;
			if(x[j]-x[i]<=d)
			{
				t[i]=j;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int k=1;k<i;k++)
		{
			if(f[k][i].num==2)
			{
				ans++;
			}
		}
		for(int j=i+1;j<=t[i];j++)
		{
			for(int k=1;k<=i;k++)
			{
				if(f[k][i].len+1<f[k][j].len)
				{
					f[k][j].len=f[k][i].len+1;
					f[k][j].num=f[k][i].num;
				}
				else if(f[k][i].len+1==f[k][j].len)
				{
					f[k][j].num+=f[k][i].num;
				}
			}
		}
	}
	cout<<ans<<endl;
	return ;
 } 
 void solve2()
 {
 	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&x[i]);
	}
	int ti=x[2]-x[1];
	if(ti*2>d)	cout<<0<<endl;
	else
	{
		int ts=d/ti;
		ts*=2;
		int ans=-ts+n+1;
		ans=max(ans,0ll);
		cout<<ans<<endl;
		
	}
	return ;
 }
 void solve3()
 {
 	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&x[i]);
	}
	int st=x[1],ed=x[n];
	int cnt=0,id=0;
	for(int i=1;i<=n;i++)
	{
		if(x[i]>=ed-d && x[i]<=st+d)
		{
			id=i;
			cnt++;
		}
	}
	if(cnt>=3)
	{
		cout<<0<<endl;
	}
 }
 signed main()
 {
 	freopen("migrate.in","r",stdin);
 	freopen("migrate.out","w",stdout);
 	int c,T;
 	cin>>c>>T;
 	if(c!=11&&c!=12 && c!=13 && c!=14)
 	{
	 	while(T--)
	 	{
	 		solve1();
		 }
	}
	else if(c==11 || c==12) 
	{
		while(T--)
		{
			solve2();
		}
	}
	else
	{
		while(T--)
		{
			solve3();
		}
	}
 	return 0;
 }
