#include<bits/stdc++.h>
#define int long long
#define ex exit(0)
#define sinzo return
#define code 0
using namespace std;
const int N=2e6+10;
int a[N],b[N],c[N],d,sz[5010][5010],sm[5010][5010];
int n,m,k,ans,cnt,sum,mx=-1e18,mn=1e18;
void dfs(int x,int sum,int fi,int la)
{
//	cout<<endl<<x<<' '<<sum<<' '<<fi<<' '<<la;
	if(x==n+1)
	{
		if(sum==sz[fi][la]+1)
		{
			sm[fi][la]++;
//			cout<<"!";
		}
		
		return;
	};
	
	if(a[x]-a[la]<=d)
	{
		if(fi==0)dfs(x+1,sum+1,x,x);
		else dfs(x+1,sum+1,fi,x);
	}
	
	dfs(x+1,sum,fi,la);
//	cout<<"R";
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T=1,c;
	cin>>c>>T;
	while(T--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c==11||c==12)
		{
			if(a[2]-a[1]>d)
			{
				//无航线
				cout<<0<<endl;
				continue;
			}if((a[2]-a[1])*2>d)
			{
				//单日出航线
				cout<<0<<endl;
				continue;
			}
			
			int c=a[2]-a[1];
			c=d/c;
			ans=n-c*2+1;
			ans=max(ans,0ll);
			cout<<ans<<endl;
			continue;
		}
		if(c<=6)
		{
			
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					sz[i][j]=1e16;
				}
				sz[i][i]=0;
			}
			
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(a[j]-a[i]<=d)
					{
						sz[i][j]=sz[j][i]=1;
					}
					
				}
			}
			for(int k=1;k<=n;k++)
			{
				for(int i=1;i<=n;i++)
				{
					for(int j=1;j<=n;j++)
					{
						if(sz[i][k]+sz[k][j]<sz[i][j])
						{
							sz[i][j]=sz[i][k]+sz[k][j];
						}
					}
				}
			}
//			for(int i=1;i<=n;i++)
//			{
//				for(int j=1;j<=n;j++)
//				{
//					cout<<sz[i][j]<<' ';
//				}
//				cout<<endl;
//			}
			if(c<=2)
			{
				dfs(1,0,0,0);
//				cout<<endl;
//				for(int i=1;i<=n;i++)
//				{
//					for(int j=1;j<=n;j++)
//					{
//						cout<<sm[i][j]<<' ';
//					}
//					cout<<endl;
//				}
				for(int i=1;i<=n;i++)
				{
					for(int j=i+1;j<=n;j++)
					{
						if(sm[i][j]==2)ans++;
						sm[i][j]=0;
					}
				}
				cout<<ans<<endl;
				
				continue;
			}
			continue;
		}
	}
	
	sinzo code;
}
/*
0 1
5 2
1 2 3 4 5


*/
/*
咕分：8+6

双日出航线？！
比翼双飞？！
二人转？！
钳击？！
同？！
？！
！

*/