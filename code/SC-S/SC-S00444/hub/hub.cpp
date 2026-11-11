#include<bits/stdc++.h>
#define int long long
#define lop(i,a,b) for(int i=a;i<=b;i++)
#define pol(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
using namespace std;
const int NN=4e3+5,INF=0x3f3f3f3f3f3f3f3f;
int n,k;
vector<int> ed[NN];
int dep[NN],lng[NN],dfn[NN],num,siz[NN],ans,dis[NN];
void DFS(int x,int fa){
	lng[x]=0,siz[x]=1;
	dfn[x]=++num;
	for(int y:ed[x]){
		if(y==fa)continue;
		dep[y]=dep[x]+1;
		DFS(y,x);
		siz[x]+=siz[y];
		lng[x]=max(lng[x],lng[y]+1);
	}
}
bool vst[NN],cho[NN];
void DFS3(int x){
//	cout<<x<<"! ";
	vst[x]=1;
	for(int y:ed[x]){
		if(vst[y])continue;
		if(cho[y])DFS3(y);
	}
	return;
}
bool Check(){
	int cnt=0;
	lop(i,1,n)vst[i]=0;
	lop(i,1,n){
		if(cho[i]&&!vst[i])DFS3(i),cnt++;
	}
//	cout<<cnt<<"@\n";
	return cnt<=2;
}
queue<int> q;
int GetAns(){
//	cerr<<"@#";
	while(!q.empty())q.pop();
	lop(i,1,n)dis[i]=INF;
	lop(i,1,n)if(cho[i])q.push(i),dis[i]=0;
	while(!q.empty()){
		int x=q.front();q.pop();
//		cerr<<x<<" #";
		for(int y:ed[x]){
			if(dis[y]==INF){
				dis[y]=dis[x]+1;
				q.push(y);
			}
		}
	}
	int res=0;
	lop(i,1,n)res=max(res,dis[i]);
//	cerr<<res<<"#\n";
	return res;
}
void DFS2(int x,int cnt){
//	cout<<"@@";
	if(cnt==k){
//		cout<<"#";
		if(Check())ans=min(ans,GetAns());
		return;
	}
	if(x>n)return;
	cho[x]=1;
	DFS2(x+1,cnt+1);
//	cout<<"!!!\n";
	cho[x]=0;
	DFS2(x+1,cnt);
	return;
}
void Work(){
	ans=INF;
	num=0;
	cin>>n>>k;
	lop(i,1,n+1)ed[i].clear();
	lop(i,1,n-1){
		int u,v;cin>>u>>v;
		ed[u].pb(v);
		ed[v].pb(u);
	}
	DFS(1,1);
	DFS2(1,0);
	cout<<ans<<"\n";
	return;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout); 
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int c,t;cin>>c>>t;
	while(t--)Work();
	return 0;
}