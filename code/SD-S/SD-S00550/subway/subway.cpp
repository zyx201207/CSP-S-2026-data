#include<bits/stdc++.h>
using namespace std;
const int N=505;
int c,n,m,d,q,k,ans=INT_MAX;
int w[N],a[500][N],t[500][N];
int pnt_to_rd[500][N];
int rd_cnt=1;
vector<int> edgs[N];

//int edg_cnt,head[N],nxt[N],ver[N];
int mp[500][500];
vector<int> ver[500];
//void add(int u,int v,int e1){
//	nxt[u]=head[u];
//	head[u]=e1;
//}
void _init(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++) cin>>a[i][j]>>t[i][j];
		pnt_to_rd[a[i][1]][rd_cnt]=t[i][1];
		edgs[a[i][1]].push_back(rd_cnt);
		for(int j=2;j<=k;j++){
			edgs[a[i][j]].push_back(rd_cnt);
			pnt_to_rd[a[i][j]][rd_cnt]=t[i][j];
			rd_cnt++;
		}
	}
	for(int i=1;i<=m;i++) for(int eg1=0;eg1<edgs[i].size();eg1++) for(int eg2;eg2<edgs[i].size();eg2++) if(eg1^eg2){
		mp[eg1][eg2]=pnt_to_rd[i][eg1]+pnt_to_rd[i][eg2];
		mp[eg2][eg1]=pnt_to_rd[i][eg1]+pnt_to_rd[i][eg2];
		ver[eg1].push_back(eg2);
		ver[eg2].push_back(eg1);
	}
	
}
int vis[N];
void dfs(int x,int step,int tgt){
	if(step>ans){
		return;
	}
	if(x==tgt){
		ans=min(ans,step);
//		cout<<"Fuck"<<endl;
		return;
	}
	vis[x]=1;
	for(int i=0;i<ver[x].size();i++) if(!vis[ver[x][i]]) dfs(ver[x][i],step+mp[x][ver[x][i]],tgt);
	vis[x]=0;
	return;
}
int x,y;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	_init();
	for(int it=1;it<=q;it++){
		cin>>x>>y;
		ans=INT_MAX;
		for(int i=0;i<edgs[x].size();i++){
			for(int j=0;j<edgs[y].size();j++){
				dfs(edgs[x][i],0,edgs[y][j]);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
