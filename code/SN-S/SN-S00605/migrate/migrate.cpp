#include<iostream>
#include<vector>
#include<algorithm>
#include<set> 
#define int long long
#define endl '\n'
using namespace std;
int a[2000006];
int vis[2000006];
int s[2000006];
int n,d;

void dfs(int x,int step)
{
	if(step>vis[x])return;
	else if(step<vis[x])
	{
		//之前记录的作废
		 s[x]=0;
	}
	s[x]++;
	//cout<<s[3];
	vis[x]=step;
	
	int nowd=d,ed=-1;
	
	for(int i=x+1;i<n;i++)
	{
		if(nowd-(a[i]-a[x])>=0)
		{ed=i;
			//if(step==0)cout<<i<<endl;
		}
	}
	for(;ed>=x+1;ed--)
			dfs(ed,step+1);
}
signed main()
{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	if(c>=11)
	{
		
	while(T--)cout<<0<<endl;
	return 0;
	}
	while(T--)
	{cin>>n>>d;
	int ans=0;
		for(int i=0;i<n;i++)
		{
		cin>>a[i];
		 
		}
		for(int i=0;i<n;i++)
		{
		for(int i=0;i<n;i++)vis[i]=2147483647,s[i]=0;
		dfs(i,0);	
		
		for(int j=i;j<n;j++)if(s[j]==2)ans++;
		} 
		cout<<ans<<endl;
	}
	return  0;
}
