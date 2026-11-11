#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1009;
int C,T;
int n,k;
struct edge{
	int to,nxt;
}e[N];
int hd[N],nE;
void add(int u,int v){
	e[++nE]=(edge){v,hd[u]};
	hd[u]=nE;
}
int lb(int x){
	return x&(-x);
}
bool check1(int x){
	int ans=0;
	while(x) x-=lb(x),ans++;
	return ans==k;
}
bool st[N],stp[N];
void bfs(int S){
	//cout<<"("<<st[1]<<")";
	queue<int> q;
	q.push(S);
	stp[S]=true;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		//cout<<u;
		for(int i=hd[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(stp[v] || !st[v]) continue;
			//cout<<"("<<u<<"->"<<v<<")";
			q.push(v);
			stp[v]=true;
		}
	}
	//cout<<" ";
}
bool check2(int x){
	for(int i=1;i<=n;i++){
		if((x>>(i-1))&1) st[i]=true;
		else st[i]=false;
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(!st[i]) continue;
		if(st[i] && stp[i]) continue;
		bfs(i);
		cnt++;
	}
	return cnt<=2;
}
int bfs_dis(int S){
	queue<pair<int,int> > q;
	q.push(make_pair(S,0));
	stp[S]=true;
	while(!q.empty()){
		int u=q.front().first,d=q.front().second;
		q.pop();
		for(int i=hd[u];i;i=e[i].nxt){
			int v=e[i].to;
			if(st[v]) return d+1;
			if(stp[v]) continue;
			q.push(make_pair(v,d+1));
			stp[v]=true;
		}
	}
	return 0;
}
void init_bfs(){
	for(int i=1;i<=n;i++) stp[i]=st[i];
}
int cal(){
	int ans=0;
	for(int i=1;i<=n;i++){
		init_bfs();
		if(st[i]) continue;
		ans=max(ans,bfs_dis(i));
	}
	return ans;
}
void init_all(){
	memset(st,0,sizeof(st));
	memset(stp,0,sizeof(stp));
	memset(hd,0,sizeof(hd));
	nE=0;
}
void init(){
	memset(st,0,sizeof(st));
	memset(stp,0,sizeof(stp));
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
	int ans=N;
	for(int i=0;i<(1<<n);i++){
		init();
		if(!check1(i)) continue;
		if(!check2(i)) continue;
		int t=cal();
		ans=min(ans,t);
		//for(int i=1;i<=n;i++) cout<<st[i];
		//cout<<" "<<t<<"\n";
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>C>>T;
	while(T--){
		init_all();
		solve();
	}
	return 0;
}
/*
0 1
15 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
5 11
5 12
12 13
13 14
14 15
*/
