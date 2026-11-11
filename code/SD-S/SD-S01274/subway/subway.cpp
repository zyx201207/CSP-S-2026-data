#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,pair<int,int> >
const int M=5e5+5,N=505,INF=0x3f3f3f3f;
int c,n,m,d,Q;
int w[M];
int k[N];
vector<int> a[N],t[N],step[N];
vector<pair<int,int> > ga[M];
priority_queue<pii,vector<pii>,greater<pii> > q;
int ans;
bool flag=1;
void bfs(int s,int e){
	ans=INF;
	while(!q.empty()) q.pop();
	if(flag){
		for(int i=1;i<=n;i++){
			for(int j=0;j<a[i].size();j++){
				step[i].push_back(INF);
			} 
		}
		flag=0;
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=0;j<a[i].size();j++){
				step[i][j]=INF;
			} 
		}
	}
	for(int i=0;i<ga[s].size();i++){
		q.push({w[s]+t[ga[s][i].first][ga[s][i].second],{ga[s][i].first,ga[s][i].second}});
		step[ga[s][i].first][ga[s][i].second]=w[s]+t[ga[s][i].first][ga[s][i].second];
	}
	while(!q.empty()){
		pii x=q.top();
		q.pop();
		if(a[x.second.first][x.second.second]==e){
			ans=min(ans,x.first+t[x.second.first][x.second.second]);
			continue; 
		}
		if(x.second.second+1<=a[x.second.first].size()-1&&x.first<step[x.second.first][x.second.second+1]){
			q.push({x.first,{x.second.first,x.second.second+1}});
			step[x.second.first][x.second.second+1]=x.first;
		}
		int now=a[x.second.first][x.second.second];
		for(int i=0;i<ga[now].size();i++){
			int newdist=x.first+t[x.second.first][x.second.second]+t[ga[now][i].first][ga[now][i].second];
			if(ga[now][i].first==x.second.first||newdist>step[ga[now][i].first][ga[now][i].second]) continue;
			q.push({newdist,{ga[now][i].first,ga[now][i].second}});
			step[ga[now][i].first][ga[now][i].second]=newdist;
		}	
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&Q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%lld",&k);
		for(int j=0;j<k;j++){
			int ai,ti;
			scanf("%lld%lld",&ai,&ti);
			a[i].push_back(ai);
			t[i].push_back(ti);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<a[i].size();j++){
			ga[a[i][j]].push_back({i,j});
		}
	}
	while(Q--){
		int x,y;
		cin>>x>>y;
		bfs(x,y);
		printf("%lld\n",ans+w[y]);
	}
	return 0;
}
