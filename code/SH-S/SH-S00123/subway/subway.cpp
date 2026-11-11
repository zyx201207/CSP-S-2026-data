#include<bits/stdc++.h>
#define intback int
#define INF 1e9
using namespace std;
const int N=509;
const int D=29;
const int Q=1e5+10;//i think the lines can turn to points
int sbout[Q];
int c,n,m,d,q;
int ans;
vector<int>to[Q+N+10],w[Q+N+10];
int dst[(Q+N+10)];
bool vst[(N+Q+10)];//dijkstra ready!
#define int long long
int dijkstra(int st,int ed){
	priority_queue<pair<int,int> >q;
	//left is the distant
	fill(vst,vst+N+Q,0);
	fill(dst,dst+N+Q,INF);
	dst[st]=0;
	vst[st]=1;
	q.push({0,st});
	while(!q.empty()){
		pair<int,int>p=q.top();
		int u=p.second;
		int dis=p.first;
		dis=-dis;
		q.pop();
		for(int i=0;i<to[u].size();i++){
			int v=to[u][i];
			if(vst[v])continue;
			if((long long)(dis+w[u][i])<dst[v]){
				dst[v]=dis+w[u][i];
				if(!vst[v]){
					q.push({-dst[v],v});
				}
			}
		}
	}
	return dst[ed];
}
set<int>OI;
int solveB(int st,int ed){//bfs infact
	queue<int>q;
	int cj=*OI.begin();//OI begin at now
	fill(vst,vst+N+Q,0);
	fill(dst,dst+N+Q,INF);
	q.push(st);
	dst[st]=0;
	while(!q.empty()){
		int u=q.front();
		vst[u]=1;
		
		q.pop();
		for(int i=0;i<to[u].size();i++){
			int v=to[u][i];
			if(vst[v])continue;
			dst[v]=dst[u]+1;
			q.push(v);
		}
		if(vst[ed])break;
	}
	return dst[ed]*cj;
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	bool B=1;

	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%d",&sbout[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			OI.insert(t);
			int b=i+m;
			to[b].push_back(a);
			to[a].push_back(b);
			w[b].push_back(t);
			w[a].push_back(t);
			
		}
	}
	B=(OI.size()==1);
	while(q--){
		int a,id;
		cin>>a>>id;
		
		ans=dijkstra(a,id)+sbout[a]+sbout[id];
		printf("%d\n",ans);
	}
	
	return 0;
}
