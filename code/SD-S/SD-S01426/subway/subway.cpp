#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int readint(){
	int x=0;
	int f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}

ll readll(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
const int INF=0x3f3f3f3f;
const int MAXN=10010;
const int MAXM=5000050;
int c,n,m,d,q;
ll w[MAXM];
ll t[MAXM];

typedef pair<ll,int> PII;
vector<PII> g[MAXM];
bool vis[MAXM];



void ask(int s,int en){
	ll ans=0;
	memset(vis,false,sizeof(vis));
	ans+=w[s];
	ans+=w[en];
	vector<ll> dis(MAXM,0x3f);
	priority_queue<PII,vector<PII>,greater<PII>> q;
	q.push({t[s],s});
	vis[s]=true;
	dis[s]=t[s];
	while(!q.empty()){
		auto e=q.top();
		q.pop();
		int u=e.second;
		ll w=e.first;
		if(w>dis[u]){
			continue;
		}
		/*if(u==en){
			break;
		}*/
		for(auto it:g[u]){
			int v=it.second;
			if(v==u){
				continue;
			}
			ll d;
			if(!vis[v]){
				d=it.first+t[v];
				vis[v]=true;	
			}else{
				d=it.first;
			}
			//ll d=it.first;
			if(dis[v]>dis[u]+d){
				dis[v]=dis[u]+d;
				q.push({dis[v],v});
			}
		}
	}
	ans+=dis[en];
	ans-=t[en];
	printf("%lld",ans);
}



int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=readint(),n=readint(),m=readint(),d=readint(),q=readint();
	for(int i=1;i<=m;i++){
		w[i]=readll();
	}
	for(int i=1;i<=n;i++){
		int k=readint();
		for(int j=1;j<=k;j++){
			int x=readint();
			ll d=readll();
			if(i==j){
				t[i]=d;
				continue;
			}
			g[i].push_back({d,x});
			g[x].push_back({d,i});
		}
	}
	//dfs(1,0);
	while(q--){
		int s=readint();
		int e=readint();
		ask(s,e);
	}
	return 0;
} 

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3 
1 2
*/

/*
0 3 7 20 2
8 3 6 1 7 2 9 
3 1 4 2 5 5 100
3 2 6 3 1 7 2 
4 3 2 5 100 4 6 6 7 
1 6 
2 3 

*/
