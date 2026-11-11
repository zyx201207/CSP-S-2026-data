#include <bits/stdc++.h>
#define int long long
const int INF=2e18;
const int N=505;
const int M=5e5+10;
using namespace std;
int c,n,m,dmax,q;//表示测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数。
struct node{
	int to,w;
	inline bool operator<(const node&tmp)const{
		return w>tmp.w;
	} 
};
int qi,zh;
int ans;
int w[M+N];
vector<node>v[N+M];
int dis[N+M];
priority_queue<node>qp;
inline void dij(int s)
{
	for(int i=1;i<=n+m;++i)
		dis[i]=INF;
	dis[s]=0;
	qp.push({s,0});
	while(!qp.empty())
	{
		auto t=qp.top();
		qp.pop();
		int x=t.to;
		int d=t.w;
		if(d>dis[x])
			continue;
		for(auto son:v[x])
		{
			int to=son.to;
			int wson=son.w;
			if(dis[to]>d+wson)
			{
				dis[to]=d+wson;
				qp.push({to,d+wson});
			}
		}
	}
	return ;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>dmax>>q;
	for(int i=1;i<=m;++i)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;++i)
	{
		int k;
		cin>>k;
		//cout<<"i  "<<k<<"\n"; 
		for(int j=1;j<=k;++j)
		{
			int to,zhi;
			cin>>to>>zhi; 
			v[i+m].push_back({to,zhi});
			v[to].push_back({i+m,zhi}); 
			//cout<<to<<" "<<zhi<<"\n";
		}
	}
	while(q--)
	{
		cin>>qi>>zh; 
		ans=0;
		ans+=w[qi]+w[zh];
		//cout<<ans<<" ";
		//cout<<qi<<" "<<zh<<"\n"; 
		dij(qi);
		cout<<ans+dis[zh]<<"\n"; 
	}
	return 0;
}
/*
n的最大值是500,这是十分有问题的
d<=20每个地铁站最多被20条线路经过 

我认为是不是要分层图
怎么分层呢
分层感觉是不好写的，我在想是不是能把站台和站厅看成不同的点跑最短路
考虑怎么转化点
地铁口不用管
我们分点的时候尽量把站台上的点为1-m这样好算答案
感觉分好点是不是就做完了
不是有n条线路吗
第i条线路我把它定义一个点为n+i
这样我不就可以直接跑最短路了吗
 
*/

