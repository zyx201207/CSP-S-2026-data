#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=5e5+10,N=510,INF=1e18;
int c,n,m,d,q,ans;
struct edge{
	int w;
	vector<int> t,sub,nw;
	map<int,int> sut;
}a[M];
int u,v;
int num[N];
vector<int> line[N];
bool vis[M];
void dfs(int now,int sum,int su){
	if(now==v){ans=min(ans,sum+a[now].sut[su]);return;}
	if(vis[now])return;
	if(sum>=ans)return;
	vis[now]=1;
	for(int i=0;i<a[now].sub.size();i++){
		int sub=a[now].sub[i],nowedge=a[now].nw[i],tim=a[now].t[i];
		if(su==0){
			dfs(line[sub][nowedge+1],sum+tim,sub);
			if(nowedge-1>=0)dfs(line[sub][nowedge-1],sum+tim,sub);
		}else if(su!=a[now].sub[i]){
			dfs(line[sub][nowedge+1],sum+a[now].sut[su]+tim,sub);
			if(nowedge-1>=0)dfs(line[sub][nowedge-1],sum+a[now].sut[su]+tim,sub);
		}else {
			dfs(line[sub][nowedge+1],sum,su);
			if(nowedge-1>=0)dfs(line[sub][nowedge-1],sum,sub);
		}
	}
	vis[now]=0;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>a[i].w;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		for(int j=0,al,t;j<num[i];j++){
			cin>>al>>t;
			line[i].push_back(al);
			a[al].t.push_back(t),a[al].sub.push_back(i);
			a[al].nw.push_back(j),a[al].sut[i]=t;
		}
		line[i].push_back(0);
	}
	while(q--){
		cin>>u>>v;
		ans=INF;
		dfs(u,0,0);
		cout<<ans+a[u].w+a[v].w<<endl;
	}
	return 0;
}
