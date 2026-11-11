#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,d,x[2020200];
vector<int>g[5555];

void funA(){
	//d:最远跳的距离 
	int D=x[2]-x[1];//两个岛之间的距离
	if(D==0 or d<=D){cout<<"0\n";return;}
	int num=d/D;//能跳过几个岛
	//显然，对于这样的双路径点对，只可能跳过2*num-1个点
	if(n<2*num)cout<<"0\n";
	else cout<<n-2*num+1<<"\n"; 
}
int dis[5555],cnt[5555];
bool vis[5555];
struct no{
	int u,d;
	bool operator<(const no&b)const{
		return d>b.d;
	}
};
void dijk(int s){
	memset(dis,63,sizeof(dis));
	memset(vis,0,sizeof(vis));
	memset(cnt,0,sizeof(cnt)); 
	dis[s]=0,cnt[s]=1;
	priority_queue<no>q;
	q.push({s,0});
	while(!q.empty()){
		int u=q.top().u;q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i = 0;i<g[u].size();i++){
			int v=g[u][i];
			if(v<s or vis[v])continue;
			if(dis[v]==dis[u]+1)cnt[v]+=cnt[u];
			else if(dis[v]>dis[u]+1){
				cnt[v]=cnt[u];
				dis[v]=dis[u]+1;
				q.push({v,dis[v]});
			}
		}
	}
}
void fun1(){//跑n次dijkstra 
	for(int i = 1;i<=n;i++)g[i].clear();
	for(int i = 1;i<=n;i++)
		for(int j = i+1;j<=n;j++)
			if(x[j]-x[i]<=d){
				g[i].push_back(j);
				g[j].push_back(i); 
			}
			else break;
	int ans=0;
	for(int i = 1;i<=n;i++){
		dijk(i);
		for(int j = i;j<=n;j++)
			if(cnt[j]==2)ans++;
	}
	cout<<ans<<endl; 
}
void fun(){
	cin>>n>>d;
	for(int i = 1;i<=n;i++)cin>>x[i];
	if(c==11 or c==12)
		funA();
	else if(n<=5000)fun1();
	
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt;
	cin>>c>>tt;
	while(tt--)fun();
	return 0;
} 

