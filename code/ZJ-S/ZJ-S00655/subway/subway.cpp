#include<iostream>
#include<bitset>
#include<vector>
#include<queue>
#define Maxn 505
#define Maxm 500005
namespace my
{
	using std::cin;
	using std::ios;
	using std::min;
	using std::cout;
	using std::pair;
	using std::queue;
	using std::vector;
	using std::bitset;
}
using namespace my;
int c;//测试点编号(垃圾) 
int n;//地铁路线数 
struct subway//地铁路线
{
	int k;//经过的地铁站数
	vector<int> a;//a[j]表示其经过第j-1个地铁站
	vector<int> t;//t[j]表示其从第j-1个地铁站走回此线路站台所需时间 
}sub[Maxn];
int m;//地铁站数
vector<int> station[Maxm];//记录这个地铁站被那些路经过 
int d;//每个地铁站最多被几条路经过 
int q;//出行计划数 
int w[Maxm];//从地铁口走到站厅的时间
bitset<Maxn> vis;//记录那些线路走过
int start,end;//出行计划的起点和终点 
int g[Maxn][Maxn];
void build(void)
{
	int x,y;
	for(int i=1;i<=m;++i)
	{
//		cout<<i<<':'<<'\n';
		for(int j=0;j<station[i].size();++j)
		{
			for(x=0;x<sub[station[i][j]].k;++x)
				if(sub[station[i][j]].a[x]==i)
				{
//					cout<<"x="<<x<<' ';
					break;
				}					
			for(int k=j+1;k<station[i].size();++k)
			{
				for(y=0;y<sub[station[i][k]].k;++y)
					if(sub[station[i][k]].a[y]==i)
					{
//						cout<<"y="<<y<<'\n';
						break;
					}
				g[x+1][y+1]=g[y+1][x+1]=sub[station[i][j]].t[x]+sub[station[i][k]].t[y];
			}
		}
//		cout<<'\n';
	}
//	for(int i=1;i<=n;++i)
//	{
//		for(int j=1;j<=n;++j)
//		{
//			cout<<g[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
}//建图(把线路看成一个点)
long long Dijkstra()
{		
	int ss=0,sc=0,ee=0,ec=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<sub[i].k;++j)
		{
//			cout<<i<<':'<<sub[i].a[j]<<' '<<start<<'\n';
			if(sub[i].a[j]==start)
			{
				ss==i;
				sc=sub[i].t[j];
			}
			if(sub[i].a[j]==end)
			{
				ee==i;
				ec=sub[i].t[j];
			}
		}
	}
	queue<pair<long long,long long>> que;
	pair<long long,long long> head;
	long long ans;
//	for(int i=0;i<station[start].size();++i)
//	{
//		for(int j=0;j<sub[station[start][i]].k;++j)
//			if(sub[station[start][i]].a[j]==i)
//			{
//				que.push({station[start][i],sub[station[start][i]].t[j]});
//				break;
//			}		
//	}
	que.push({ss,sc});	
	vis[ss]=true;
	while(!que.empty())
	{
		head=que.front();
//		cout<<head.first<<' '<<head.second<<'\n';
		que.pop();
		if(head.first==ee)
		{
			ans=head.second;
			break;
		}
		for(int i=1;i<=n;++i)
		{
			if(head.first==i)
				continue;
			if(!vis[i]&&g[head.first][i])
			{
				vis[i]=true;
//				cout<<head.second<<'+'<<g[head.first][i]<<'\n';
				que.push({i,head.second+g[head.first][i]});
			}
		}			
	}
//	cout<<ans<<' '<<ec<<'\n';
	return ans+ec;
}
/*
bitset<Maxn> vis;//记录那些线路走过
queue<pair<int,long long>> que;//记录出行所经过的线路和目前走过的步数 
pair<int,long long> head;//pair<目前所在线路,已走步数>
long long travel(int train,int step)//DFS?
{
	long long ans=2e9;
	que.push({train,step});
	while(!que.empty())
	{
		head=que.front();
		que.pop();
		if(head.second>=ans)
			continue;//剪枝 
		for(int i=0;i<=sub[head.first].a.size();++i)//遍历这条线路
		{
			if(sub[head.first].a[i]==end)//走到终点
			{
				ans=min(ans,head.second+sub[head.first].t[i]);//保存答案 
				continue;
			} 
			for(int j=0;j<station[sub[head.first].a[i]].size();++j)//找能走的线路
			{
				if(!vis[station[sub[head.first].a[i]][j]])//这条线路还没走过
				{
					vis[station[sub[head.first].a[i]][j]]=true;//标记
					int k;
					for(k=0;k<=sub[station[sub[head.first].a[i]][j]].t.size();++k)//找位置 
						if(station[sub[head.first].a[i]][j]==sub[station[sub[head.first].a[i]][j]].t[k])
							break;
					que.push({station[sub[head.first].a[i]][j],head.second+sub[head.first].t[i]+sub[station[sub[head.first].a[i]][j]].t[k]});
				} 
			}
		}		
	}
	return ans;
}
*/
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)
	{
		cin>>w[i];
	}
	int a,t;
	for(int i=1;i<=n;++i)
	{
		cin>>sub[i].k;
		for(int j=1;j<=sub[i].k;++j)
		{
			cin>>a>>t;
			station[a].push_back(i);//第a个站被第i条路经过 
			sub[i].a.push_back(a);
			sub[i].t.push_back(t);
		}
	}
	build();
	for(int i=1;i<=q;++i)
	{
		cin>>start>>end;
		cout<<w[start]+w[end]+Dijkstra()<<'\n';
	}
	return 0;
}
