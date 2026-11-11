#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,Q;
int w[500040];
struct p{
	int to,e;
};
vector<p>g[500040];
struct pp{
	int x,y,id;
}que[100005];
bool cmp(pp a, pp b){
	return a.x<b.x;
}
long long s[500040];
bool vis[500040];
long long ans[100005];
priority_queue<p>q;
bool operator<(const p& a,const p& b){
	return a.e>b.e;
} 
void djik(int st){
	memset(vis,0,sizeof(vis));
	memset(s,0x3f,sizeof(s));
	while(!q.empty()){
		q.pop();
	}
	q.push({st,0});
	s[st]=0;
	while(!q.empty()){
		int u=q.top().to;
		q.pop();
		if(vis[u]){
			continue;
		}
		vis[u]=1;
		for(int i=0;i<g[u].size();i++){
			if(vis[g[u][i].to]){
				continue;
			}
			if(s[g[u][i].to]>s[u]+g[u][i].e){
				s[g[u][i].to]=s[u]+g[u][i].e;
				q.push({g[u][i].to,s[g[u][i].to]});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int u,e;
			cin>>u>>e;
			g[m+i].push_back({u,e});
			g[u].push_back({m+i,e});
		}
	}
	for(int i=1;i<=Q;i++){	
		int x,y;
		cin>>x>>y;
		if(x>y){
			swap(x,y);
		}
		que[i].x=x;
		que[i].y=y;
		que[i].id=i;
	}
	sort(que+1,que+1+Q,cmp);
	int last=0;
	for(int i=1;i<=Q;i++){
		//cout<<que[i].x<<' '<<que[i].y<<'\n';
		if(que[i].x!=last){
			djik(que[i].x);
			last=que[i].x;
			//for(int j=1;j<=m;j++){
			//	cout<<s[j]<<' ';
			//}
			//cout<<'\n';
		}
		ans[que[i].id]=w[que[i].x]+w[que[i].y]+s[que[i].y];
	}
	for(int i=1;i<=Q;i++){
		cout<<ans[i]<<'\n';
	}
	return 0;
}
//subway.out subway4.ans
