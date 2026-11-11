#include<bits/stdc++.h>//SN-S00495 闫可心 陕西省西安中学 
using namespace std;
const int N=501,M=1000001,D=20;
int c,n,m,d,q,dist[N],arr[N];
vector< pair<int,int> > sta[M];
vector<int> sub[M];
int take(int start,int end)
{
	memset(dist,0x3f,sizeof(dist));
	dist[start]=0;
	priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > pq;
	pq.push({start,0});
	int id=start;
	while(!pq.empty())
	{
		int x=pq.top().first;
		int y=pq.top().second;
		pq.pop();
		if(y>dist[id]) continue;
		for(int i=0;i<sta[x].size();i++)
		{
			int v=sta[x][i].first;
			for(int j=0;j<sub[v].size();j++)
			{
				int ti=sub[v][j];
				int w=y+sta[ti][v].second;
				if(dist[ti]>dist[x]+w)
				{
					dist[ti]=dist[x]+w;
					int id=ti;
					pq.push({ti,dist[ti]});
				}
			}
		}
	}
	if(dist[end]==0x3f3f3f3f) return -1;
	else return arr[start]+arr[end]+dist[end];
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++) cin>>arr[i];
	for(int i=0;i<n;i++)
	{
		int k;
		cin>>k;
		while(k--)
		{
			int a,b;
			cin>>a>>b;
			sta[a].push_back({i,b});
			sub[i].push_back(a);
		}
	}
	while(q--)
	{
		int start,end;
		cin>>start>>end;
		cout<<take(start,end)<<'\n';
	}
	return 0;
}
