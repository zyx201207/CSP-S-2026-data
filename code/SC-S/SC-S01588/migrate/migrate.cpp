#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n,d,x[N],cnt[N],dis[N];
void dfs(int nw,int len)
{
	
	if(len<dis[nw])
	{
		dis[nw]=len;
		cnt[nw]=1;
		for(int i=nw+1;i<=n;i++)
		{
			if(x[i]-x[nw]<=d)
			{
				dfs(i,len+1);
			}
		}
	}
	else if(len==dis[nw])
	{
		cnt[nw]++;
		if(cnt[nw]>=3)
		{
			return;
		}
		for(int i=nw+1;i<=n;i++)
		{
			if(x[i]-x[nw]<=d)
			{
				dfs(i,len+1);
			}
		}
	}
	else
	{
		return;
	}
}
main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i],dis[i]=INT_MAX;
		for(int i=1;i<=n;i++)
		{
			dis[i]=0;
			dfs(i,0);
			for(int j=i;j<=n;j++)
			{
				if(cnt[j]==2)ans++;//,cout<<i<<" "<<j<<"\n";
				cnt[j]=0;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}//40pts