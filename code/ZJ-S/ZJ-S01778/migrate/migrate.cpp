#include<bits/stdc++.h>
#define PII pair<int,int>
using namespace std;
int c,T,h[2500010],e[2500010],ne[250010],idx;
long long n,d,a[2000010],dis[5010][5010],cnt[5010][5010];
bool vis[2000010];
void add(int x,int y){
	cnt[x][y]=1;
	e[idx]=y;
	ne[idx]=h[x];
	h[x]=idx++;
}
void bfs(int st){
	for(int i=1;i<=n;i++) vis[i]=0;
	priority_queue<PII,vector<PII>,greater<PII> >q;
	dis[st][st]=0;
	q.push({0,st});
	while(!q.empty()){
		PII t=q.top();
		q.pop();
		int d=t.second;
		if(vis[d]) continue;
		vis[d]=1;
		for(int i=h[d];~i;i=ne[i]){
			int j=e[i];
			if(dis[st][j]>dis[st][d]+1){
				dis[st][j]=dis[st][d]+1;
				q.push({dis[st][j],j});
			}
		}
	}
}
void solv(){
	memset(h,-1,sizeof h);
	idx=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[i]<=d) add(i,j);
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++) cnt[i][i]=1;
	for(int i=1;i<=n;i++) bfs(i);
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=i+1;k<j;k++){
				if(dis[i][k]+dis[k][j]==dis[i][j]) cnt[i][j]++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(cnt[i][j]==2) ans++;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--) solv();
	return 0;
}
