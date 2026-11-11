/*
yeah i wrote 95 lines of codes just for 6pts;
limbuscompany limbuscompany limbuscompany limbuscompany limbuscompany
limbuscompany limbuscompany limbuscompany limbuscompany limbuscompany
limbuscompany limbuscompany limbuscompany limbuscompany limbuscompany
limbuscompany limbuscompany limbuscompany limbuscompany limbuscompany
limbuscompany limbuscompany limbuacompany limbuscompany limbuscompany
limbuscompany limbuscompany limbuscompany limbuscompany limbuscompany
limbuscompany limbuscompany limbuscompany limbuscompany limbuscompany
limbuscompany limbuscompany limbuscompany limbuscompany limbuscompany
limbuscompany limbuscompany limbuscompany limbuscompany limbuscompany
limbuscompany limbuscompany limbuscompany limbuscompany limbuscompany
,,,,,,,well
jm99 jm99 jm99 jm99 jm99 jm99 jm99 jm99 jm99 jm99
jm99 jm99 jm99 jm99 jm99 jm99 jm99 jm99 jm99 jm99
jm99 jm99 jm99 jm99 jm99 jm99 jm99 jm99 jm99 jm99
jm99 jm99 jm99 jm99 jm99 jm99 jm99 jm99 jm99 jm99
jm99 jm99 jm99 jm99 jm99 jm99 jm99 jm99 jm99 jm99

han zhong nai bei fa jian feng , wen chang ke gan dang tai shou zhe ze ?
shu dai jian xian , liang cao ru he yun shu ?
bei fa kong hao guo li , bu ru xiao fa dong wu .
wu hu jin sheng ji yi , shui gan dang bei fa xian feng ?
you he bu gan? !
ji cheng xian di yi zhi , qi neng kun shou bu qian ? AHHHHHHH !!!!!
*/
#include<bits\stdc++.h>
using namespace std;
const int maxn=105;
int c,t,n,k,ans;
vector<int> g[maxn];
bool choose[maxn];

bool connected(){
	int cnt=0;
	bool vis[maxn];
	memset(vis,false,sizeof vis);
	for(int i=1;i<=n;i++){
		if(choose[i]&&!vis[i]){
			cnt++;
			queue<int> q;
			q.push(i);
			vis[i]=true;
			while(q.size()){
				int u=q.front();
				q.pop();
				for(int y:g[u]){
					if(choose[y]&&!vis[y]){
						vis[y]=true;
						q.push(y);
					}
				}
			}
		}
	}
	return cnt<=2;
}

void trythis(){
	if(!connected()){
		return;
	}
	int vis[maxn],thisans=0;
	memset(vis,-1,sizeof vis);
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(choose[i]){
			q.push(i);
			vis[i]=0;
		}
	}
	while(q.size()){
		int u=q.front();
		q.pop();
		thisans=max(thisans,vis[u]);
		for(int y:g[u]){
			if(vis[y]==-1){
				vis[y]=vis[u]+1;
				q.push(y);
			}
		}
	}
	ans=min(ans,thisans);
}

void dfs(int u,int x){
	if(x==k){
		trythis();
	}
	if(u>n){
		return;
	}
	choose[u]=true;
	dfs(u+1,x+1);
	choose[u]=false;
	dfs(u+1,x);
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			g[i].clear();
		}
		int u,v;
		for(int i=1;i<=n-1;i++){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		ans=INT_MAX;
		dfs(1,0);
		cout<<ans<<"\n";
	}
	return 0;
}