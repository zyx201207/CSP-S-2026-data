#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int c,n,m,d,q,cnt,head[N+1005],f[N+1005],wx[N],ans[100005];
struct answers{
	int sta,en;
}quest[100005],quests[100005];
struct node{
	int to,nxt,w;
}e[2*N];
bool vis[N+1005];
struct dot{
	int idx,wi;
};
struct cmp{
	bool operator()(dot x,dot y)const{
		return x.wi>y.wi;
	}
};
priority_queue<dot,vector<dot>,cmp>que;
inline void add(int u,int v,int w){
	cnt++;
	e[cnt].w=w;
	e[cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
inline bool relax(int u,int v,int w){
	if(f[u]+w<f[v]){
		f[v]=f[u]+w;
		return 1;
	}
	return 0;
}
void dijkstra(int s){
	memset(vis,0,sizeof(vis));
	memset(f,0x3f3f3f3f3f3f3f3f,sizeof(f));
	f[s]=0;
	que.push({s,f[s]});
	while(!que.empty()){
		dot nows=que.top();
		que.pop();
		int u=nows.idx;
		if(vis[u])continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to,w=e[i].w;
			if(vis[v])continue;
			if(relax(u,v,w))que.push({v,f[v]});
		}
	}
}
signed main(){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>wx[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int v,w;
			cin>>v>>w;
			add(m+i,v,w);
			add(v,m+i,w);
		}
	}
	for(int i=1;i<=q;i++){
		cin>>quest[i].sta>>quest[i].en;
		quests[i].sta=quest[i].sta;
		quests[i].en=quest[i].en;
	}
	sort(quest+1,quest+q+1,[](answers x,answers y){
		if(x.sta==y.sta)return x.en<y.en;
		return x.sta<y.sta;
	});
	for(int i=1;i<=q;i++){
		if(quest[i].sta==quest[i-1].sta)ans[i]=1ll*(wx[quest[i].sta]+f[quest[i].en]+wx[quest[i].en]);
		else{
			dijkstra(quest[i].sta);
			ans[i]=1ll*(wx[quest[i].sta]+f[quest[i].en]+wx[quest[i].en]);
		}
	}
	for(int i=1;i<=q;i++){
		int l=1,r=q,ansque=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(quest[mid].sta==quests[i].sta&&quest[mid].en==quests[i].en){
				ansque=mid;
				break;
			}else if(quest[mid].sta==quests[i].sta&&quest[mid].en<quests[i].en)l=mid+1;
			else if(quest[mid].sta==quests[i].sta&&quest[mid].en>quests[i].en)r=mid-1;
			else if(quest[mid].sta>quests[i].sta)r=mid-1;
			else l=mid+1;
		}
		cout<<ans[ansque]<<'\n';
	}
	return 0;
}


