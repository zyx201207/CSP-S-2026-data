#include<bits/stdc++.h>
using namespace std;
int c,t1;
long long f=1,t=0,dp[2000010];
long long n,d,x[2000010];
struct node{
	int x;
	int step;
}st,ed,q[2000010];

void bfs(node st,node ed)
{
	int minn=0x7f;
	q[++t]=st;
	
	while(f<=t)
	{
		node u=q[f++];
		if(u.x==ed.x && u.step==minn)
		{
			dp[ed.x]++;
			continue;
		}
		if(u.x==ed.x && u.step<minn)
		{
			minn=u.step;
			dp[ed.x]=1;
			continue;
		}
		if(u.x>ed.x)continue;
		for(int i=u.x+1;i<=ed.x;i++)
		{
			if(x[i]-x[u.x]<=d)
			{
				node v;
				v.x=i;
				v.step=u.step+1;
				q[++t]=v;
			}
			else 
			{
				break;
			}
			
		}
	}
	
	return;
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t1;
	for(int i=1;i<=t1;i++)
	{
		int cnt=0;
		cin>>n>>d;
		for(int j=1;j<=n;j++)
		{
			cin>>x[j];
		}
		for(int j=1;j<=n;j++)
		{
			st.x=j;
			st.step=0;
			for(int l=j+1;l<=n;l++)
			{
				ed.x=l;
				bfs(st,ed);
				if(dp[ed.x]==2)cnt++;
			}
		}
		cout<<cnt;
	}
	return 0;
}
