#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int N=5e5+5;
int cece,n,m,d,qqq,w[N],k[N],cnt;
long long dis[N*3];
struct point2
{
	int dao,num;
};
vector<point2> a[N];
vector<int> t[N];
bool bj[N*3];
struct point
{
	int dao;
	long long val;
};
vector<point> v[N*3];
priority_queue<point> q;
bool operator<(point x,point y)
{
	return dis[x.dao]>dis[y.dao];
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>cece>>n>>m>>d>>qqq;
	cnt=m;
	for(int i=1;i<=m;i++){cin>>w[i];}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int x,y;
			cin>>x>>y;
			a[i].push_back({x,++cnt}),t[i].push_back(y);
			v[x].push_back({cnt,y});
			v[cnt].push_back({x,y});
//			cout<<x<<" "<<cnt<<" "<<y<<"\n";
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<a[i].size();j++)
			for(int kk=0;kk<a[i].size();kk++)
			{
				if(j==kk){continue;}
				point2 w1=a[i][j],w2=a[i][kk];
				v[w1.num].push_back({w2.num,0});
//				cout<<w1.num<<" "<<w2.num<<" "<<0<<"\n";
			}
	
	while(qqq--)
	{
		int x,y;
		cin>>x>>y;
		for(int i=1;i<=cnt;i++){dis[i]=0x3f3f3f3f3f3f3f3f;}
		while(!q.empty()){q.pop();}
		dis[x]=0;
		q.push({x,0});
		while(!q.empty())
		{
			point jiu=q.top();
			q.pop();
			bj[jiu.dao]=0;
			for(int i=0;i<v[jiu.dao].size();i++)
			{
				point p=v[jiu.dao][i];
				if(dis[p.dao]<=dis[jiu.dao]+p.val){continue;}
				dis[p.dao]=dis[jiu.dao]+p.val;
				if(!bj[p.dao]){bj[p.dao]=1;q.push({p.dao,dis[p.dao]});}
			}
		}
//		for(int i=1;i<=2*m;i++){cout<<i<<" "<<dis[i]<<"\n";}
		cout<<dis[y]+w[x]+w[y]<<"\n";
	}
	return 0;
}

