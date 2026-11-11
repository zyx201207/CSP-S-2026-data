#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,M=2e6+5;
int c,t,n,k,x,y,ans,dis[1005][1005];
int head[N],nxt[M],to[M],cnt=-1;
void add(int u,int v){
	cnt++;
	nxt[cnt]=head[u];
	to[cnt]=v;
	head[u]=cnt;
}
queue<int> q;
bool vis[1005];
void bfs(int x,int fa){
	memset(dis[x],0x3f,sizeof(dis[x]));
	memset(vis,0,sizeof(vis));
	dis[x][x]=0;
	q.push(x);
	while(q.size()){
		int u=q.front();
		q.pop();
		vis[u]=true;
		for(int i=head[u];i!=-1;i=nxt[i]){
			if(vis[to[i]]) continue;
			dis[x][to[i]]=dis[x][u]+1;
			q.push(to[i]);
		}
	}	
}
vector<int> s;
void check(int x){
	s.clear();
	memset(vis,0,sizeof(vis));
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(x&(1<<(i-1))&&!vis[i]){
			cnt++;
			vis[i]=true;
			s.push_back(i);
			for(int j=head[i];j!=-1;j=nxt[j]){
				if(x&(1<<(to[j]-1))){
					vis[to[j]]=true;
					s.push_back(to[j]);
				}
			}
		}
	}
	if(cnt>2) return;
	int sum=1e9,num=0;
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		sum=1e9;
		for(int j=0;j<s.size();j++){
			sum=min(sum,dis[i][s[j]]);
		}
		num=max(num,sum);
	}
	ans=min(ans,num);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&k);
		if(n==k){
			printf("%d\n",0);
			continue;
		}
		memset(head,-1,sizeof(head));
		for(int i=1;i<n;i++){
			scanf("%d%d",&x,&y);
			add(x,y);
			add(y,x);
		}
		if(k<=20&&n<=1000){
			ans=1e9;
			for(int i=1;i<=n;i++) bfs(i,i);
			for(int i=1;i<(1<<n);i++){
				if(__builtin_popcount(i)>k||__builtin_popcount(i)<k) continue;
				check(i);
			}
			printf("%d\n",ans);
		}
		else{
			printf("%d\n",1);
		} 
	}
	return 0;
}