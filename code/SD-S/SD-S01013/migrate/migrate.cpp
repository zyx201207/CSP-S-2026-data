#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int n,c,m,dis[N],tag[N],t,cnt,k,ga;
int a[N],d;
queue<int> q;
vector<int> v[N];
void dfs(int x,int y){
	tag[x]=1;
	if(y==k){
		if(x==ga) cnt++;
		return ;
	}
	for(int i=0;i<v[x].size();i++){
		int xx=v[x][i];
		if(!tag[xx]){
			dfs(xx,y+1);
			tag[xx]=0;
		}
	}
}
int bs(int x,int y){
	while(!q.empty()) q.pop();
	memset(tag,0,sizeof(tag));
	memset(dis,0,sizeof(dis));
	q.push(x);
	dis[x]=0;
	tag[x]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(u==y) return dis[y];
		for(int i=0;i<v[u].size();i++){
			int xx=v[u][i];
			if(!tag[xx]){
				q.push(xx);
				dis[xx]=dis[u]+1;
				tag[xx]=1;
			}
		}
	}
	return dis[y];
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld %lld",&c,&t);
	while(t--){
		int ans=0;
		scanf("%lld %lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if((a[j]-a[i])>d) continue;
				v[i].push_back(j);
				v[j].push_back(i);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cnt=0;
				k=bs(i,j);
				memset(tag,0,sizeof(tag));
				ga=j;
				dfs(i,0);
				if(cnt==2){
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
		for(int i=1;i<=n;i++) v[i].clear();
	}
	return 0;
}
