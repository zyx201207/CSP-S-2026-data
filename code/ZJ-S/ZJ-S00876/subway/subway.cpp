#include<bits/stdc++.h>
using namespace std;
typedef pair<long long,int> pli;
int w[500010],k,n,m,d,q;
vector<pair<int,int>> query[500010],v[10000010];
long long f[10000010],ans[100010];
bool updates[10000010]; 
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%*d%d%d%d%d",&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",w+i);
	k=m;
	for(int i=1;i<=n;i++)
	{
		int len,lst,x,y;
		scanf("%d%d%d",&len,&x,&y);
		lst=++k;
		v[x].push_back({k,y});
		v[k].push_back({x,y});
		for(int j=2;j<=len;j++)
		{
			scanf("%d%d",&x,&y);
			k++;
			v[x].push_back({k,y}); v[k].push_back({x,y});
			v[lst].push_back({k,0}); v[k].push_back({lst,0});
			lst=k;
		}
	}
	for(int i=1;i<=q;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		query[u].push_back({v,i});
	}
	for(int st=1;st<=m;st++)
	{
		if(query[st].empty()) continue;
		for(int i=1;i<=k;i++) f[i]=0x3f3f3f3f3f3f3f3f,updates[i]=0;
		f[st]=0;
		priority_queue<pli,vector<pli>,greater<pli>> pq;
		pq.push({0,st});
		updates[st]=1;
		while(!pq.empty())
		{
			int now=pq.top().second; pq.pop();
			if(!updates[now]) continue;
			updates[now]=0;
			for(auto edge:v[now])
			{
				int to=edge.first,val=edge.second;
				if(f[now]+val<f[to])
				{
					f[to]=f[now]+val;
					pq.push({f[to],to});
					updates[to]=1;
				}
			}
		}
		for(auto i:query[st])
			ans[i.second]=f[i.first]+w[i.first]+w[st];
	}
	for(int i=1;i<=q;i++) printf("%lld\n",ans[i]);
	return 0;
}
//十年OI一场空，不开long long见祖宗。long long渡江洒江郊，高者AC长林梢，下者CE沉塘坳。AK选手欺我暴力慢，忍能对面写样例。卡完剪枝卡常数，一堆循环减不得，归来调试自叹息。