#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=2*N,inf=0x3f3f3f3f;
int id,n,m,res,ts;
int e[M],ne[M],h[N],idx;
int dist[N],d[N];
bool st[N];
bool op[N];

void add(int a,int b){
	e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void subA(){
	int l=(n-1)/2;
	for(int i=0;i<=n;i++){
		int tt=l-2*i-m;
		if(tt%2) tt=tt/2+2;
		else tt=tt/2+1;
		if(tt<=i){
			printf("%d\n",i);
			return;
		}	
	}
}

void cl(int x){
	queue<int> q;
	q.push(x);
	while(q.size()){
		int t=q.front();
		q.pop();
		for(int i=h[t];i!=-1;i=ne[i]){
			int j=e[i];
			if(op[j]){
				q.push(j);
				op[j]=0;
			}
		}
	}
}

bool check(){
	for(int i=1;i<=n;i++) op[i]=st[i];
	
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(op[i]){
			cnt++;
			if(cnt>2) return false;
			cl(i);
		}
	}
	
	if(cnt==2) return true;
	return false;
}

void bfs(){
	memset(dist,0x3f,sizeof(dist));
	queue<int> q;
	for(int i=1;i<=n;i++)
		if(st[i]){
			q.push(i);
			dist[i]=0;
		}
	while(q.size()){
		int t=q.front();
		q.pop();
		for(int i=h[t];i!=-1;i=ne[i]){
			int j=e[i];
			if(dist[j]>dist[t]+1){
				dist[j]=dist[t]+1;
				q.push(j);
			}
		}
	}
	
	int tmp=0;
	for(int i=1;i<=n;i++) tmp=max(tmp,dist[i]);
	res=min(res,tmp);
}

void dfs(int u,int s){
	if(u==n+1){
		if(s==m&&check()){
			bfs();
		}
		return;
	}
	
	st[u]=1;
	dfs(u+1,s+1);
	st[u]=0;
	dfs(u+1,s);
	
	return;
}

void solve(){
	res=inf;
	dfs(1,0);
	printf("%d\n",res);
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	scanf("%d%d",&id,&ts);
	while(ts--){
		memset(h,-1,sizeof(h));
		scanf("%d%d",&n,&m);
		for(int i=1;i<n;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			add(a,b);
			add(b,a);
		}
		if(id>6) subA();
		else solve();
	}
	return 0;
}
