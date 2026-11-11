#include<bits/stdc++.h>
using namespace std;
const long long N=501,M=5e5+1;
struct stu{
	long long st;
	long long dis;
	bool operator<(const stu &p)const{
		return dis>p.dis;
	}
};
long long c,n,m,d,q;
long long w[M];
long long k[N];
vector<long long>g[N];
vector<long long>gg[M];
int dd[M][N];
bool fl[N];
bool flag[M];
long long bfs(long long u,long long v);
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++)cin>>w[i];
	bool neq2[M][5]={};
	for(long long i=1;i<=n;i++){
		cin>>k[i];
		for(long long j=1;j<=k[i];j++){
			long long x,y;
			cin>>x>>y;
			neq2[x][i]=1;
			dd[x][i]=y;
			g[i].push_back(x);
			gg[x].push_back(i);
		}
	}
	if(n==1){
		while(q--){
			long long u,v;
			cin>>u>>v;
			cout<<w[u]+w[v]+dd[u][1]+dd[v][1]<<'\n';
		}
		return 0;
	}
	if(n==2){
		long long tmp=LLONG_MAX;
		for(long long i=1;i<=m;i++){
			if(neq2[i][1]&&neq2[i][2]){
				tmp=min(tmp,(long long)(dd[i][1]+dd[i][2]));
			}
		}
		while(q--){
			long long u,v;
			cin>>u>>v;
			if(neq2[u][1]&&neq2[v][1]){
				if(neq2[u][2]&&neq2[v][2])cout<<w[u]+w[v]+min(dd[u][1]+dd[v][1],dd[u][2]+dd[v][2])<<'\n';
				else cout<<w[u]+w[v]+dd[u][1]+dd[v][1]<<'\n';
			}else if(neq2[u][2]&&neq2[v][2])cout<<w[u]+w[v]+dd[u][2]+dd[v][2]<<'\n';
			else if(neq2[u][1]&&neq2[v][2])cout<<w[u]+w[v]+dd[u][1]+dd[v][2]+tmp<<'\n';
			else cout<<w[u]+w[v]+dd[u][2]+dd[v][1]+tmp<<'\n';
		}
		return 0;
	}
	while(q--){
		long long u,v;
		cin>>u>>v;
		cout<<bfs(u,v)<<'\n';
	}
	return 0;
}
long long bfs(long long u,long long v){
	priority_queue<stu>q;
	q.push({u,w[u]});
	memset(fl,0,sizeof fl);
	memset(flag,0,sizeof flag);
	flag[u]=1;
	while(!q.empty()){
		auto p=q.top();
		q.pop();
		long long st=p.st;
		long long dis=p.dis;
		if(st==v)return dis+w[v];
		for(long long i:gg[st]){
			if(fl[i])continue;
			fl[i]=1;
			long long d_1=dd[st][i];
			for(long long j:g[i]){
				if(flag[j])continue;
				flag[j]=1;
				long long d_2=dd[j][i];
				q.push({j,dis+d_1+d_2});
			}
		}
	}
	return -1;
}