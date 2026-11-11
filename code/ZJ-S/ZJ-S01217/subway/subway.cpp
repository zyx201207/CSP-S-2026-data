#include <bits/stdc++.h>
using namespace std;
typedef pair<long long,long long> PII;
typedef pair<long long,pair<long long,long long>> PII2;
const int N=5e5+10;
const long long INF=1e18;
int w[N];
int n1[N];
vector<PII> g[510];
int c,n,m,d,T; 
int l,r; 
long long dist[N];
void dijkstra(){
	memset(dist,0x3f,sizeof dist);	
	priority_queue<PII2,vector<PII2>,greater<PII2>> q;
	dist[l]=w[l];
	q.push({w[l],{l,-1}});
	while (!q.empty()){
		int t=q.top().second.first,t1=q.top().second.second;
		q.pop();
		if (t1!=-1){
			for (int i=0;i<=n1[i];i++){
				if (dist[g[t1][i].first]>dist[t]+g[t1][i].second){
					dist[g[t1][i].first]=dist[t]+g[t1][i].second;
						q.push({dist[g[t1][i].first],{g[t1][i].first,t1}});					
				}
			}
		}
		for (int i=1;i<=n;i++){
			int flag=0,step=0;
			for (int j=0;j<=n1[i];j++){
				if (g[i][j].first==t){
					flag=1;
					step=j;
					break;
				}
			}
			if (flag){
				for (int j=0;j<=n1[i];j++){
					if (j!=step){
						if (dist[g[i][j].first]>dist[t]+g[i][j].second+g[i][step].second){
							dist[g[i][j].first]=dist[t]+g[i][j].second+g[i][step].second;	
							q.push({dist[g[i][j].first],{g[i][j].first,i}});
						}						
					}

				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>T;
	for (int i=1;i<=m;i++)cin>>w[i];
	for (int i=1;i<=n;i++){
		cin>>n1[i];
		for (int j=1;j<=n1[i];j++){
			int a,t;
			cin>>a>>t;
			g[i].push_back({a,t});
		}
		n1[i]--;
	}
	while (T--){
		cin>>l>>r;
		dijkstra();
		cout<<dist[r]+w[r]<<endl;
	}
	return 0;
} 
