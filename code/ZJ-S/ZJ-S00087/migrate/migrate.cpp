#include<bits/stdc++.h>
#define int long long
using namespace std;
int x[2550001],n,d;
int fd(int t)//find
{
	return upper_bound(x+1,x+1+n,t)-x-1;
}
int vis[2550001];
int rem[2550001];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int ans=0,i,j;
		cin>>n>>d;
		for(i=1;i<=n;i++)
		{
			cin>>x[i];
		}
//		for(i=1;i<=n;i++)
//		{
//			cout<<fd(x[i]+d)<<' ';
//		}
//		cout<<endl;
		for(i=1;i<=n;i++)
		{
			rem[i]=fd(x[i]+d);
		}
		for(i=1;i<=n;i++)
		{
			int tp=i,la=i-1;//tp1~tp2-1 ->2 tp2~tp3 ->1  
			for(j=1;j<=n;j++)vis[j]=0;
			vis[i]=1;
			while(1)
			{
				int t;
				t=rem[tp];
				for(j=tp+1;j<=rem[tp];j++)
				{
					vis[j]+=vis[tp];
				}
				if(tp-1>la)
				{
					for(j=tp+1;j<=rem[tp-1];j++)
					{
						vis[j]+=vis[tp-1];
					}	
				}
				if(tp-2>la)
				{
					for(j=tp+1;j<=rem[tp-2];j++)
					{
						vis[j]+=vis[tp-2];
					}	
				}
				for(j=tp+1;j<=t;j++)
				{
					if(vis[j]==2)
					{
//						cout<<"ans:"<<i<<' '<<j<<endl;
						ans++;
					}
				}
//				for(j=tp+1;j<=t;j++)
//				{
//					cout<<vis[j]<<' ';
//				}
//				cout<<endl;
				if(tp>=t)
				{
					break;
				}
				la=tp;
				tp=t;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
