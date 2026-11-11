//换乘的次数尽可能少 
//这个题面很诡异啊
//这t数组的下标含糊不清
//毁了我的迪杰斯特拉
//咋不早说样例解释有问题 
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,tot,ans;
struct node{
	int id;
	int dist;
	bool operator<(const node &x)const{
		return x.dist<dist;
	}
};
priority_queue<node> pq;
int w[500005];
int dis[500005];
bool flag[500005];
int a[505][500005];
int t[505][500005];
vector<int> graph[500005];
void dijkstra() 
{
	
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}	
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[i][j]>>t[i][j];
			graph[a[i][j]].push_back(a[i][j-1]);
			graph[a[i][j-1]].push_back(a[i][j]); 
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		ans=w[x]+w[y];
		
	}
	return 0;
}

