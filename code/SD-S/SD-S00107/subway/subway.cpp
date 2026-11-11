#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using ll=long long;
using namespace std;
const int N=1e6+10;
const int M=2e6+10;
struct node{
	int to;
	ll w;
	int nxt;
}e[M];
struct bfsq{
	int u,last;
	ll dd;
};
ll step[N];
int head[N];
bool vis[N];
int len;
void add(int u,int v,ll w){
	e[++len].to=v;
	e[len].nxt=head[u];
	e[len].w=w;
	head[u]=len;
}
ll dis[N];int c,n,m,d,q;
ll bfs(int start,int end){
	memset(vis,0,sizeof(vis));
	queue<bfsq>q;
	q.push({start,-1,0});
	vis[start]=1;
	while(!q.empty()){
		int u=q.front().u;
		ll dd=q.front().dd;
		int last=q.front().last;
		q.pop();
		if(u==end){
			return dd;
		}
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to;
			ll w=e[i].w;
			if((!vis[v]||v>m)){
				vis[v]=1;
				if(last>m&&v>m&&v==last){
					q.push({v,u,dd});
				}
				else q.push({v,u,dd+w});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	rep(i,1,m){
		cin>>step[i];
	}
	rep(i,1,n){
		int k;
		cin>>k;
		rep(j,1,k){
			int a;
			ll t;
			cin>>a>>t;
			add(a,m+i,t);
			add(m+i,a,t);
			
		}
	}
	rep(i,1,q){
		int s,e;
		cin>>s>>e;
		cout<<step[s]+bfs(s,e)+step[e]<<"\n";
	}
	return 0;
}

