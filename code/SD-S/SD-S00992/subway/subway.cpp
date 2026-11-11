#include<iostream>//T2 胡编乱造 求25Tips 求省二 
#define int long long
using namespace std;
const int M=5e5+10;
const int N=2005;
int w[M],k[N];
int f_i,f_j,flag;
int c,n,m,d,q,ans=0;
struct sub{
	int st;//站台几？
	int time;//多长时间？ 
}a[N][5]/*第几站？*/;
struct road{
	int x;//起点
	int y;//终点 
}p[M];//计划几？ 
void read()
{
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];//表示从每个地铁站的地铁口
				//走到站厅需要的时间。
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{ 
			cin>>a[i][j].st/*第i条线路的第j站是a[i][j].st*/>>a[i][j].time;
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>p[i].x>>p[i].y;
	}	
}
void find(int x,int num)
{
	for(int i=num;i<=n;i++)
	{
		for(int j=num;j<=2;j++)
		{ 
			//cin>>a[i][j].st/*第i条线路的第j站是a[i][j].st*/>>a[i][j].time;
			if(a[i][j].st==x)
			{
				f_i=i;
				f_j=j;
				return ;
			} 
		}
	}
	flag=-1;
}
void work(int qqq)
{
	find(p[qqq].x,qqq);
	for(int i=1;i<=d;i++)
	{
		if(flag<0)break;
		if(f_j==1)
		{
			if(a[f_i][2].st!=p[i].y)
			{
				ans+=a[f_i][f_j].time;
				find(a[f_i][2].st,i);
				ans+=a[f_i][f_j].time;
			}
			else
			{
				return ;
			}
		}
		else
		{
			if(a[f_i][1].st!=p[i].y)
			{
				ans+=a[f_i][f_j].time;
				find(a[f_i][1].st,i);
				ans+=a[f_i][f_j].time;
			}
			else
			{
				return ;
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	read();
	for(int i=1;i<=q;i++)
	{
		ans+=w[p[i].x];
		ans+=w[p[i].y];
		work(i);
		cout<<ans<<'\n';
	}
	return 0;
}


