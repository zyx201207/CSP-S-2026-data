#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define maxn 514
#define maxm 2145
LL c,n,m,d,Q;
LL w[maxm];
LL dist[maxm][maxm];
vector<pair<LL,LL>>e[maxm]; //1~500为地铁线路（站台） 500以上为地铁站（站厅）
priority_queue<pair<LL,LL>,vector<pair<LL,LL>>,greater<pair<LL,LL>>>q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(LL i=1;i<=m;i++)cin>>w[i];
	LL k,a,b,ti;
	for(LL i=1;i<=n;i++){
		cin>>k;
		for(LL j=1;j<=k;j++){
			cin>>a>>ti;
			e[a+500].push_back({i,ti});
			e[i].push_back({a+500,ti});
		}
	}
	memset(dist,0x7f,sizeof(dist));
	for(LL i=1;i<=m;i++){
		while(!q.empty())q.pop();
		dist[i+500][i+500]=0;
		for(auto x:e[i+500]){
			q.push({x.second,x.first});
		}
		while(!q.empty()){
			LL pos=q.top().second;
			LL dis=q.top().first;
			q.pop();
			if(dis>=dist[i+500][pos])continue;
			dist[i+500][pos]=dis;
			for(auto x:e[pos]){
				q.push({x.second+dis,x.first});
			}
		}
	}
	while(Q--){
		cin>>a>>b;
		cout<<dist[a+500][b+500]+w[a]+w[b]<<endl;
	}
	return 0;
}
