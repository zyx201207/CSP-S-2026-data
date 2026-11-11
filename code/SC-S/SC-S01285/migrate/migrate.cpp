#include<bits/stdc++.h>
/*

pts 24 ~ 40
time 17:18
up_date 
- 18:24 还剩 6 min 疑似想到正解...，单调队列维护区间 + 双指针维护答案 O(N)
*/
using namespace std;
typedef long long ll;
typedef pair<int,int> pt;
const int N = 2e6 + 1000 ;
int T,c;
ll n,d;
ll a[N];
struct node{
	int to,w;
};
vector<int> g[N];
int dist[N];
bool vis[N];
int cnt[N];
queue<int> q;
void bfs(int s){
	memset(dist,0x3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	memset(cnt,0,sizeof(cnt));
	dist[s]=0;
	q.push(s);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int v:g[u]){
			if(dist[v]==dist[u]+1){
				cnt[v]++;
				q.push(v);
				continue;
			}
			if(dist[v]>dist[u]+1){
				dist[v]=dist[u]+1;
				q.push(v);
			}
		}
	}
}
int main (){
//	freopen("migrate1.in","r",stdin);
//	freopen("migrate.ans","w",stdout);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		for(int i=1;i<=n;i++)	g[i].clear();
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			int op=upper_bound(a+i,a+1+n,a[i]+d)-a-1;
			if(op>n)	op=n;
			//cout<<a[i]<<" "<<a[op]<<"\n";
			for(int j=i+1;j<=op;j++){
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
		int ans=0;
		for(int k=1;k<=n;k++){
			bfs(k);
			for(int i=1;i<=n;i++){
				if(cnt[i]==1)	ans++;
			}
		}
		cout<<ans/2<<"\n";
	}
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