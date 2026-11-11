#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;
int n,k;
vector<int> g[N];

inline void init(){
	cin>>n>>k;
	for(int i=0;i<=n+1;i++) g[i].clear();
	for(int i=1;i<n;i++){
		int u,v; cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
}

inline int num1(int x){
	int res=0,t=x;
	while(t){
		if(t%2==1) res++;
		t/=2;
	}
	return res;
}
int tag[30],vis[30];
void dfs(int cur,int fa){
	vis[cur]=1;
	for(int i=0;i<(int)g[cur].size();i++){
		int v=g[cur][i];
		if(v!=fa&&vis[v]==0&&tag[v]==1){
			dfs(v,cur);
		}
	}
	return ;
}
inline bool check(int x){
	int res=0;
	for(int i=0;i<=n+1;i++) tag[i]=0,vis[i]=0;
	for(int i=1;i<=n;i++){
		if((1<<(i-1))&x) tag[i]=1;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]&&tag[i]) dfs(i,0),res++;
	}
	if(res<=2) return true;
	return false;
}
inline void solve1(){
	int dis[20][20];
	int res=1e9;
	memset(dis,0x3f,sizeof(dis));
	
	for(int i=1;i<=n;i++){
		for(int j=0;j<(int)g[i].size();j++){
			int v=g[i][j];
			dis[i][v]=1;
			dis[v][i]=1;
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(i!=j&&i!=k&&j!=k){
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
	}
	for(int i=1;i<=(1<<n);i++){
		if(num1(i)==k){
			if(check(i)){
				int ccf=0;
				for(int j=1;j<=n;j++){
					int tr=1e9;
					if(tag[j]) continue;
					for(int k=1;k<=n;k++){
						if(tag[k]==1){
							tr=min(tr,dis[j][k]);
						}
					}
					ccf=max(ccf,tr);
				}
//				cout<<"tr= "<<tr<<"\n";
				res=min(res,ccf);
			}
		}
	}
	cout<<res<<"\n";
}
int sta,maxx=1;
void dfs1(int cur,int fa,int step){
	if(step>maxx){
		sta=cur;
		maxx=step;
	}
	for(int i=0;i<(int)g[cur].size();i++){
		int v=g[cur][i];
		if(fa!=v){
			dfs1(v,cur,step+1);
		}
	}
	return ;
}

void solve2(){
	maxx=1;
	dfs1(1,0,1);
	maxx=1;
	dfs1(sta,0,1);
	if(maxx&1) cout<<(maxx+1)/4<<"\n";
	else cout<<maxx/4<<"\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	int C,T;
	cin>>C>>T;
	while(T--){
		init();
		if(n==k) cout<<"0\n";
		else if(n<=100) solve1();
		else if(k==2) solve2();
	}
	
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/