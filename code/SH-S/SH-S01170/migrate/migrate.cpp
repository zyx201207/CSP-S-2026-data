#include<bits/stdc++.h>
#define int long long
using namespace std; 

const int N=2e5+5e4+5;

int c,t,n,d;

int x[N];
int np[N];


int st;
int sum[N];
bool vis[N];
bool vs[N];
vector<int>mp[N];

void dfs(int a,bool ad)
{
	vis[a]=1;
	if(!ad)
	{
		sum[a]+=1;
	}
	for(int i=0;i<mp[a].size();i++)
	{
		if(!vis[mp[a][i]])
		{
			if(mp[a][i]-x[a]<d)
			{
				dfs(mp[a][i],0);
			}
			else
			{
				dfs(mp[a][i],1);
			}
			
			vis[mp[a][i]]=0;
		}
	}
	return ;
}

void solve()
{
	int ans=0;
	for(int i=0;i<=d;i++)
	{	
		mp[i].clear();
	}
	for(int i=1;i<n;i++)
	{
		st=x[i];
//		cout<<'\n'<<i<<":\n";
//		cout<<st<<": ";
		for(int j=1;j<=d;j++)
		{
			int tg=upper_bound(x+1,x+n+1,st+j)-x-1;
//			cout<<tg<<' ';
			if(x[tg]!=st+j||tg>n)
			{
				continue; 
			}
			else
			{
				cout<<tg<<' ';
				mp[i].push_back(tg);
			}
		}
//		cout<<'\n';
	}
	memset(vs,0,sizeof(vs));
	for(int i=1;i<n;i++)
	{
		memset(vis,0,sizeof(vis));
		memset(sum,0,sizeof(sum));
		dfs(i,0);
		for(int j=1;j<=n;j++)
		{
			if(sum[j]==2&&!vs[j])
			{
				vs[j]=1;
				ans++;
			}
		}
//		cout<<'\n';
	}
	cout<<ans<<'\n';
}

signed main()
{
	freopen("migrate.in","r",stdin);	
	freopen("migrate.out","w",stdout);	
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>d;
		for(int j=1;j<=n;j++)
		{
			cin>>x[j];	
		}
//		cout<<"one of the question has been already input"<<'\n';
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
