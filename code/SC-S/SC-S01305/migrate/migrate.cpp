#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;

int c,T;
int n,d;
int a[N],ans;
vector<int>g[N];
int in[N], dis[N];//距离 
int w[N];//个数 
int ini[N];
void dfs(){
	queue<int>q;
	for(int i=1;i<=n;i++){
		q.push(i);
		for(auto v:g[i-1]) in[v]--;
		for(int j=1;j<=n;j++) ini[j]=in[j],w[j]=0,dis[j]=1000000;
		
		ini[i]=0;
		dis[i]=0;
		while(q.size()){
			int u=q.front();
			q.pop();
			for(auto v:g[u]){
				if(dis[u]+1<dis[v]){
					dis[v]=dis[u]+1;
					w[v]=1;
				}
				else if(dis[u]+1==dis[v]) w[v]++;
				ini[v]--;
				if(ini[v]==0) q.push(v);
			}
		}
		while(q.size()) q.pop();
		for(int j=1;j<=n;j++){
			if(w[j]==2) ans++;
			//cout<<w[j]<<" ";
		}
		//cout<<"\n";
	}
	for(int i=1;i<=n;i++) ini[i]=0,w[i]=0,dis[i]=1000000,in[i]=0;

}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]+d<a[j]) break;
				g[i].push_back(j);
				in[j]++;
			}
		}
		dfs();
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++) g[i].clear();
		ans=0;
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/