#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t,n;
long long d,x[N];
vector<int>G[N];
int cnt,minn;
bool f[N];
void dfs(int x,int y,int now)
{
	if(x==y)
	{
		if(now<minn)minn=now,cnt=1;
		else if(now==minn)cnt++;
		return;
	}
	for(int i=0;i<G[x].size();i++)
		if(f[G[x][i]]==false and G[x][i]!=-1)
		{
			f[G[x][i]]=true;
			dfs(G[x][i],y,now+1);
			f[G[x][i]]=false;
		}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)G[i].empty();
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			for(int j=1;j<i;j++)
				if(abs(x[i]-x[j])<=d)
				{
					G[i].push_back(j);
					G[j].push_back(i);
				}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				cnt=0,minn=INT_MAX;
				memset(f,false,sizeof(f));
				dfs(i,j,0);
				if(cnt==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
