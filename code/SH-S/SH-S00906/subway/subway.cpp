#include<iostream>
#include<cstring>
#include<queue>
#include<utility>
#include<vector>
using namespace std;
typedef long long ll; 
const int Maxm=5e5+5;
int c,n,m,d,q;
ll w[Maxm];
vector<int> sub_p[505];
ll sub_t[505][Maxm];
vector<int> station[Maxm];
ll dis[Maxm];
vector<pair<int,int> > ask[Maxm];
ll ans[500005];
void dijkstra(int st)
{
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > pq;
	dis[st]=0;
	pq.push(make_pair(0LL,st));
	while(!pq.empty()){
		pair<ll,int> cur=pq.top();
		pq.pop();
		ll pos=cur.second,wt=cur.first;
		if(wt!=dis[pos]) continue;
		for(int ii=0;ii<(int)station[pos].size();++ii){
			int i=station[pos][ii];
			for(int jj=0;jj<(int)sub_p[i].size();++jj){
				int j=sub_p[i][jj];
				if(j==pos) continue;
				ll v=dis[pos]+sub_t[i][j]+sub_t[i][pos];
				if(v<dis[j]){
					dis[j]=v;
					pq.push(make_pair(v,j));
				}
			}
		}
	}
	/*for(int i=1;i<=m;++i){
		cout<<dis[i]<<" ";
	}
	cout<<"\n";*/
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1;i<=n;++i)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;++j){
			int x;
			cin>>x;
			cin>>sub_t[i][x];
			sub_p[i].push_back(x);
			station[x].push_back(i);
		}
	}
	for(int i=1;i<=q;++i){
		int xi,yi;
		cin>>xi>>yi;
		/*memset(dis,0x3f,sizeof(dis));
		dijkstra(xi);
		cout<<dis[yi]+w[xi]+w[yi]<<"\n";*/
		if(xi>yi) swap(xi,yi);
		ask[xi].push_back(make_pair(yi,i));
	}
	
	for(int i=1;i<=m;++i){
		if(ask[i].size()==0) continue;
		memset(dis,0x3f,sizeof(dis));
		dijkstra(i);
		for(int j=0;j<(int)ask[i].size();++j){
			ans[ask[i][j].second]=dis[ask[i][j].first]+w[i]+w[ask[i][j].first];
		}
	}
	for(int i=1;i<=q;++i){
		cout<<ans[i]<<"\n";
	}
	return 0;
 } 
