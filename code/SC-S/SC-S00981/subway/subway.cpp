#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,n,m,d,Q;
int w[1000001],dis[2001],vis[2001],k[1000001];
vector<int>a[1000001];
vector<int>t[1000001];
int ans[505][505];
struct node{
	int to,v;
	friend bool operator<(node nn,node nnn){
		return nn.v>nnn.v;
	}
};
vector<node>edge[1000001];
bool cmp(node nn,node nnn){
	return vis[nn.to]<vis[nnn.to];
}
void dij(int s){
	for(int i=1;i<=n;i++)vis[i]=0,dis[i]=1e18;
	vis[s]=1;dis[s]=0;
	priority_queue<node>q;
	q.push({s,0});
	while(!q.empty()){
		node nw=q.top();
		q.pop();
		int u=nw.to,x=nw.v;
		vis[u]=1;
		sort(edge[u].begin(),edge[u].end(),cmp);
		for(auto v:edge[u]){
			int vv=v.to,ss=v.v;
			if(vis[vv])break;
			if(ss+x<dis[vv]){
				dis[vv]=ss+x;
				q.push({vv,dis[vv]});
			}
		}
	}
}
int min_dis[505][505];
int ans_dis[505][505];
struct node2{
	int a1,t1;
};
vector<node2>road[1000001];
int qwqqwqa1[1001],qwqqwqt1[1001];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>C>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int aaa,bbb;
			cin>>aaa;
			a[i].push_back(aaa);
			cin>>bbb;
			t[i].push_back(bbb);
			road[aaa].push_back({i,bbb});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			min_dis[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<road[i].size();j++){
			for(int ij=j+1;ij<road[i].size();ij++){
				int j_n=road[i][j].a1,ij_n=road[i][ij].a1;
				min_dis[j_n][ij_n]=min(min_dis[j_n][ij_n],road[i][j].t1+road[i][ij].t1);
				min_dis[ij_n][j_n]=min(min_dis[ij_n][j_n],road[i][j].t1+road[i][ij].t1);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(min_dis[i][j]==1e18)continue;
			edge[i].push_back({j,min_dis[i][j]});
			edge[j].push_back({i,min_dis[i][j]});
		}
	}
	for(int i=1;i<=n;i++){
		dij(i);
		for(int j=1;j<=n;j++){
			ans_dis[i][j]=dis[j];
		}
	}
	for(int i=1;i<=Q;i++){
		int xr,yr;
		cin>>xr>>yr;
		int res=1e18;
		for(int j=0;j<road[yr].size();j++)qwqqwqa1[j]=road[yr][j].a1,qwqqwqt1[j]=road[yr][j].t1;
		for(int j=0;j<road[xr].size();j++){
			int res1=1e18;
			int xxx=road[xr][j].a1;
			for(int k=0;k<road[yr].size();k++){
				res1=min(res1,ans_dis[xxx][qwqqwqa1[k]]+qwqqwqt1[k]);
			}
			res=min(res,res1+road[xr][j].t1);
		}
		cout<<res+w[xr]+w[yr]<<'\n';
	}
	return 0;
}
