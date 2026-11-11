#include<bits/stdc++.h>
using namespace std;
struct note
{
	int a,t;
};
note a[510][50010];
int t[500010];
int k[500010];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c;//啥也不是
	int n;//地铁路线数
	int m;//地铁站数
	int d;//每个地铁站最多被几条路线行经过
	int q;//出行计划数 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>t[i];
	}
	for(int i=1;i<=n;i++)
	{
	//第i条路线中经过的站点数
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j].a>>a[i][j].t;
		}
	}
	queue<note> qq;
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		qq.push({x,y});
	}
	//目标：稳住20分，剩下不要了，就n<=3，1 2 3往过枚，一定可以，加油 
	if(n==1)
	{
		for(int j=1;j<=q;j++)
		{
			int ans=0;
			note now=qq.front();
			qq.pop();
			ans+=t[now.a];
			ans+=t[now.t];
//			cout<<now.a<<' '<<now.t<<"\n";
			for(int i=1;i<=k[1];i++)
			{
				if(a[1][i].a==now.a)
				{
					ans+=a[1][i].t;
				}
				if(a[1][i].a==now.t)
				{
					ans+=a[1][i].t;
				}
			}
			cout<<ans<<"\n";
		}
	}
	else if(n==2)
	{
		while(!qq.empty())
		{
			note now=qq.front();
			qq.pop();
			int ans=0x3f3f3f3f;
			for(int i=1;i<=2;i++)
			{
				for(int j=1;j<=k[i];j++)
				{
					if(a[i][j].a==now.a)
					{
						for(int e=1;e<=k[i];e++)
						{
							if(a[i][e].a==now.t)
							{
								ans=min(ans,t[now.a]+t[now.t]+a[i][j].t+a[i][e].t);
								break;
							}
						}
						if(i==1)
						{
							int p=2;
						}
						else
						{
							int p=1;
						}
						for(int e=1;e<=k[i];e++)
						{
							ans++; 
							//好难好难好难难，模不出来，暴力也出不来，真难受 
						}
					}
				}
			}
		}
	}
	return 0;
}
//希望能拿八分，四分也行，求求求求求求 
/* 0 1 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
1 2 
1 4*/
