#include<bits/stdc++.h>
using namespace std;
long long k[505],w[100005];
vector< pair<long long,long long> > line[505];
long long x[100005],y[100005],Ans[100005];
long long dis[1005][1005],p[20005];
vector<long long> ans[1005];
long long d[1005];
struct Node{
	long long x,w;
	bool operator<(const Node& ot)const{
		return w>ot.w;
	}
};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	long long c,n,m,dt,q;
	cin>>c>>n>>m>>dt>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++){
		cin>>k[i];
		line[i].push_back({0,0});
		for(long long j=1,x,y;j<=k[i];j++){
			cin>>x>>y;
			line[i].push_back({x,y});
		}
	}
	for(long long i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		ans[x[i]].push_back(i),p[x[i]]=1;
	}
	if(c!=0){
		memset(dis,0x3f,sizeof dis);
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=k[i];j++){
				for(long long l=1;l<j;l++){
					dis[line[i][j].first][line[i][l].first]=dis[line[i][l].first][line[i][j].first]=min(dis[l][j],
					line[i][j].second+line[i][l].second);
				}
			}
		}
		for(long long i=1;i<=m;i++) dis[i][i]=0;
		for(long long i=1;i<=m;i++){
			if(p[i]){
				priority_queue<Node> q;
				for(long long j=1;j<=m;j++) d[j]=0x3f3f3f3f3f3f3f3f;
				d[i]=0;q.push({i,0});
				while(!q.empty()){
					Node u=q.top(); q.pop();
					if(u.w!=d[u.x]) continue;
					for(long long j=1;j<=m;j++){
						if(d[j]>dis[u.x][j]+d[u.x]){
							d[j]=dis[u.x][j]+d[u.x];
							q.push({j,d[j]});
						}
					}
				}
				for(long long j=0;j<ans[i].size();j++){
					long long tsk=ans[i][j];
					Ans[tsk]=d[y[tsk]];
				}
			}
		}	
		for(long long i=1;i<=q;i++){
			cout<<Ans[i]+w[x[i]]+w[y[i]]<<"\n";
		}
	}
	return 0;
}
