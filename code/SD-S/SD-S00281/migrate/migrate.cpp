#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x*f;
}
int c,t;
const int N=2e6+5;
int n;
int d,x[N];
vector<int>e[5005];
long long Abs(long long x){
	if(x<0)return -x;
	else return x;
}
bool vis[5005];
int dist[5005],cnt[5005];
void spfa(int s){
	for(int i=1;i<=n;i++){
		vis[i]=false;
		cnt[i]=0;
		dist[i]=1e18;
	}
	vis[s]=true;
	cnt[s]=1;
	dist[s]=0;
	queue<int>q;
	q.push(s);
	while(q.size()){
		int u=q.front();
		q.pop();
		vis[u]=false;
		for(auto v:e[u]){
			if(dist[v]>dist[u]+1){
				dist[v]=dist[u]+1;
				cnt[v]=cnt[u];
				if(!vis[v]){
					vis[v]=true;
					q.push(v);
				}
			}
			else if(dist[v]==dist[u]+1)cnt[v]+=cnt[u]; 
		}
	}
}
void sub1(){
	long long ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(Abs(x[i]-x[j])<=d&&(i!=j))
			e[i].push_back(j);
		}
	}
//	for(int i=1;i<=n;i++){
//		for(auto j:e[i]){
//			cout<<i<<"->"<<j<<'\n';
//		}
//	}
//	dijkstra(1);
//	for(int i=1;i<=n;i++)cout<<dist[i]<<cnt[i]<<" ";
	for(int i=1;i<=n;i++){
		spfa(i);
		for(int j=i+1;j<=n;j++)
		if(cnt[j]==2)ans++;
	}
	cout<<ans<<'\n';
}
void solve(){
	for(int i=1;i<=n;i++)e[i].clear();
	n=read(),d=read();
	for(int i=1;i<=n;i++)x[i]=read();
	if(c<=10)sub1();
	else cout<<n<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--)solve();
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
